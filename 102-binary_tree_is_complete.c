#include "binary_trees.h"

/**
 * size_tree - counts nodes.
 */
size_t size_tree(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + size_tree(tree->left) + size_tree(tree->right));
}

/**
 * is_complete - checks complete using index.
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
		is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - checks if tree is complete.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_complete(tree, 0, size_tree(tree)));
}
