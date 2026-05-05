int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr;
	size_t i = 0;

	if (!heap || !size)
		return (NULL);

	*size = binary_tree_size(heap);

	arr = malloc(sizeof(int) * (*size));
	if (!arr)
		return (NULL);

	while (heap)
		arr[i++] = heap_extract(&heap);

	return (arr);
}
