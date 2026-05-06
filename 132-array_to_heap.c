#include "binary_trees.h"

/**
 * array_to_heap - builds a max heap from an array
 * @array: array of integers
 * @size: size of array
 *
 * Return: pointer to root of heap
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *root = NULL;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (!heap_insert(&root, array[i]))
			return (NULL);
	}

	return (root);
}
