#include "binary_trees.h"

/**
 * check_bst - helper.
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (check_bst(tree->left, min, tree->n) &&
		check_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if valid BST.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_bst(tree, -2147483648, 2147483647));
}
