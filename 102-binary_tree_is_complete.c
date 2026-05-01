#include "binary_trees.h"

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * check_complete - Checks if a binary tree is complete by index
 * @tree: Pointer to the root node of the tree
 * @index: Current node index
 * @size: Size of the tree
 *
 * Return: 1 if complete, otherwise 0
 */
int check_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (check_complete(tree->left, 2 * index + 1, size) &&
		check_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_complete(tree, 0, tree_size(tree)));
}
