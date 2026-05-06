#include "binary_trees.h"
#include <stdlib.h>

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
 * heap_to_sorted_array - converts heap to sorted array
 * @heap: heap root
 * @size: pointer to store size
 *
 * Return: sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i = 0;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap);

	array = malloc(sizeof(int) * (*size));
	if (!array)
		return (NULL);

	while (heap)
		array[i++] = heap_extract(&heap);

	return (array);
}
