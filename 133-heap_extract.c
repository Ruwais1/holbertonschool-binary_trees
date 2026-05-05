int heap_extract(heap_t **root)
{
	heap_t *last, *tmp;
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	last = get_last_node(*root);
	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);

	tmp = *root;
	while (tmp)
	{
		heap_t *largest = tmp;

		if (tmp->left && tmp->left->n > largest->n)
			largest = tmp->left;
		if (tmp->right && tmp->right->n > largest->n)
			largest = tmp->right;

		if (largest == tmp)
			break;

		int t = tmp->n;
		tmp->n = largest->n;
		largest->n = t;

		tmp = largest;
	}

	return (value);
}
