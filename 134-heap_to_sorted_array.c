#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - converts heap to sorted array
 * @heap: heap root
 * @size: pointer to store size
 *
 * Return: array sorted in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i = 0;

	if (!heap || !size)
		return (NULL);

	*size = binary_tree_size(heap);

	array = malloc(sizeof(int) * (*size));
	if (!array)
		return (NULL);

	while (heap)
		array[i++] = heap_extract(&heap);

	return (array);
}
