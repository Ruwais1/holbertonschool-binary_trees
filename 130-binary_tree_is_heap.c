/**
 * binary_tree_is_heap - checks if a binary tree is a max heap
 * @tree: root
 * Return: 1 if heap, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int size);
int heap_order(const binary_tree_t *tree);

int tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

int is_complete(const binary_tree_t *tree, int index, int size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, size) &&
			is_complete(tree->right, 2 * index + 2, size));
}

int heap_order(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);

	if (tree->right == NULL)
		return (tree->n >= tree->left->n &&
				heap_order(tree->left));

	return (tree->n >= tree->left->n &&
			tree->n >= tree->right->n &&
			heap_order(tree->left) &&
			heap_order(tree->right));
}

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int size;

	if (!tree)
		return (0);

	size = tree_size(tree);

	return (is_complete(tree, 0, size) &&
			heap_order(tree));
}
