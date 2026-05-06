#include "binary_trees.h"

/**
 * binary_tree_size - returns size of tree
 * @tree: root
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) +
			binary_tree_size(tree->right));
}

/**
 * get_parent - finds parent for insertion
 * @root: root
 * @index: index
 * Return: parent node
 */
heap_t *get_parent(heap_t *root, size_t index)
{
	heap_t *parent = root;
	size_t mask;

	for (mask = 1 << (sizeof(size_t) * 8 - 2); !(index & mask); mask >>= 1)
		;

	mask >>= 1;

	while (mask > 1)
	{
		parent = (index & mask) ? parent->right : parent->left;
		mask >>= 1;
	}

	return (parent);
}

/**
 * heapify_up - fixes heap after insert
 * @node: inserted node
 */
void heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
}

/**
 * heap_insert - inserts value into max heap
 * @root: root
 * @value: value
 *
 * Return: new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new;
	size_t size;

	if (!root)
		return (NULL);

	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	size = binary_tree_size(*root) + 1;

	parent = get_parent(*root, size);

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if ((size & 1) == 0)
		parent->left = new;
	else
		parent->right = new;

	heapify_up(new);

	return (new);
}
