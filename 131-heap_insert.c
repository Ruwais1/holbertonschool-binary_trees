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
 * build_path - builds path to insertion point
 * @path: array
 * @depth: pointer to depth
 * @index: index
 */
void build_path(int *path, int *depth, size_t index)
{
	while (index > 1)
	{
		path[(*depth)++] = index % 2;
		index /= 2;
	}
}

/**
 * follow_path - moves to parent node
 * @root: root
 * @path: path array
 * @depth: depth
 * Return: parent node
 */
heap_t *follow_path(heap_t *root, int *path, int depth)
{
	while (depth > 1)
		root = path[--depth] ? root->right : root->left;

	return (root);
}

/**
 * heapify_up - fixes heap property
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
	int path[64], depth = 0;

	if (!root)
		return (NULL);

	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	size = binary_tree_size(*root) + 1;

	build_path(path, &depth, size);
	parent = follow_path(*root, path, depth);

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (path[0])
		parent->right = new;
	else
		parent->left = new;

	heapify_up(new);

	return (new);
}
