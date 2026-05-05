heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;
	size_t size, i;
	int path[64], depth = 0;

	if (!root)
		return (NULL);

	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	size = binary_tree_size(*root) + 1;

	i = size;
	while (i > 1)
	{
		path[depth++] = i % 2;
		i /= 2;
	}

	parent = *root;
	while (depth > 1)
		parent = path[--depth] ? parent->right : parent->left;

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (path[0])
		parent->right = new;
	else
		parent->left = new;

	while (new->parent && new->n > new->parent->n)
	{
		int tmp = new->n;
		new->n = new->parent->n;
		new->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}
