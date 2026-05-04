#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		if (root->right == NULL)
		{
			temp = root->left;
			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
