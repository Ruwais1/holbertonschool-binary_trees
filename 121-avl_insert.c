#include "binary_trees.h"

/**
 * r_insert_node - recursive helper function to insert a value in an AVL tree
 * @tree: double pointer to the root node of the AVL tree struct
 * @parent: parent node of the current tree
 * @new: double pointer to store the newly created node
 * @val: value to insert
 *
 * Return: pointer to the new root after insertion, or NULL on failure
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int val)
{
	int bval;

	if (*tree == NULL)
	{
		*new = binary_tree_node(parent, val);
		if (*new == NULL)
			return (NULL);
		*tree = *new;
		return (*tree);
	}

	if ((*tree)->n > val)
	{
		r_insert_node(&(*tree)->left, *tree, new, val);
		if (*new == NULL)
			return (NULL);
	}
	else if ((*tree)->n < val)
	{
		r_insert_node(&(*tree)->right, *tree, new, val);
		if (*new == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bval = binary_tree_balance(*tree);

	if (bval > 1 && (*tree)->left->n > val)
		*tree = binary_tree_rotate_right(*tree);
	else if (bval > 1 && (*tree)->left->n < val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bval < -1 && (*tree)->right->n < val)
		*tree = binary_tree_rotate_left(*tree);
	else if (bval < -1 && (*tree)->right->n > val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree for inserting
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	r_insert_node(tree, *tree, &new, value);

	return (new);
}
