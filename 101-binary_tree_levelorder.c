#include "binary_trees.h"

/**
 * height - Measures height.
 */
size_t height(const binary_tree_t *tree)
{
	size_t l, r;

	if (!tree)
		return (0);

	l = height(tree->left);
	r = height(tree->right);

	return ((l > r ? l : r) + 1);
}

/**
 * print_level - prints nodes at level.
 */
void print_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else
	{
		print_level(tree->left, func, level - 1);
		print_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - level order traversal.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (!tree || !func)
		return;

	h = height(tree);

	for (i = 1; i <= h; i++)
		print_level(tree, func, i);
}
