#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *curr, *new_node;
	size_t size, mask;
	int temp;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	size = binary_tree_size(*root) + 1;
	for (mask = 1; mask <= size; mask <<= 1)
		;
	mask >>= 2;
	curr = *root;
	while (mask > 1)
	{
		if (size & mask)
			curr = curr->right;
		else
			curr = curr->left;
		mask >>= 1;
	}
	new_node = binary_tree_node(curr, value);
	if (size & 1)
		curr->right = new_node;
	else
		curr->left = new_node;

	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		temp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;
		new_node = new_node->parent;
	}
	return (new_node);
}
