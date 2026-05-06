#include "binary_trees.h"

/**
 * tree_size - returns size of tree
 * @tree: root
 * Return: size
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) +
			tree_size(tree->right));
}

/**
 * is_complete - checks if tree is complete
 * @tree: root
 * @index: index
 * @size: size
 * Return: 1 or 0
 */
int is_complete(const binary_tree_t *tree, int index, int size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
			is_complete(tree->right, 2 * index + 2, size));
}

/**
 * heap_order - checks max heap property
 * @tree: root
 * Return: 1 or 0
 */
int heap_order(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);

	if (!tree->right)
		return (tree->n >= tree->left->n &&
				heap_order(tree->left));

	return (tree->n >= tree->left->n &&
			tree->n >= tree->right->n &&
			heap_order(tree->left) &&
			heap_order(tree->right));
}

/**
 * binary_tree_is_heap - checks if tree is max heap
 * @tree: root
 * Return: 1 or 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = tree_size(tree);

	return (is_complete(tree, 0, size) &&
			heap_order(tree));
}
