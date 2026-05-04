#include "binary_trees.h"

/**
 * avl_balance_node - Balances a single node in an AVL tree
 * @node: The node to balance
 *
 * Return: Pointer to the new root of this subtree
 */
avl_t *avl_balance_node(avl_t *node)
{
	int bval;

	if (node == NULL)
		return (NULL);

	bval = binary_tree_balance(node);

	if (bval > 1 && binary_tree_balance(node->left) >= 0)
		return (binary_tree_rotate_right(node));
	if (bval > 1 && binary_tree_balance(node->left) < 0)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (bval < -1 && binary_tree_balance(node->right) <= 0)
		return (binary_tree_rotate_left(node));
	if (bval < -1 && binary_tree_balance(node->right) > 0)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}

/**
 * get_successor - Get the next node in in-order traversal
 * @node: The tree to check
 *
 * Return: The minimum node in this tree
 */
avl_t *get_successor(avl_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		temp = get_successor(root->right);
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	return (avl_balance_node(root));
}
