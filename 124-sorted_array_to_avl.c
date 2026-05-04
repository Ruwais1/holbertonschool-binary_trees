#include "binary_trees.h"

/**
 * build_avl - Helper function to build an AVL tree from a sorted array
 * @parent: Pointer to the parent node of the current subtree
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created subtree, or NULL
 */
avl_t *build_avl(avl_t *parent, int *array, size_t size)
{
	avl_t *node;
	size_t mid;

	if (size == 0 || array == NULL)
		return (NULL);

	mid = (size - 1) / 2;
	node = binary_tree_node(parent, array[mid]);
	if (node == NULL)
		return (NULL);

	node->left = build_avl(node, array, mid);
	node->right = build_avl(node, array + mid + 1, size - 1 - mid);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(NULL, array, size));
}
