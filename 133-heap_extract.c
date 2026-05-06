#include "binary_trees.h"

/**
 * get_last - finds last node in level order
 * @root: root
 * Return: last node
 */
heap_t *get_last(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear)
	{
		root = queue[front++];

		if (root->left)
			queue[rear++] = root->left;
		if (root->right)
			queue[rear++] = root->right;
	}

	return (root);
}

/**
 * heapify_down - fixes heap after extraction
 * @root: root
 */
void heapify_down(heap_t *root)
{
	heap_t *largest;
	int tmp;

	while (root)
	{
		largest = root;

		if (root->left && root->left->n > largest->n)
			largest = root->left;

		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		tmp = root->n;
		root->n = largest->n;
		largest->n = tmp;

		root = largest;
	}
}

/**
 * heap_extract - extracts root of heap
 * @root: root
 * Return: value
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_last(*root);

	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);

	heapify_down(*root);

	return (value);
}
