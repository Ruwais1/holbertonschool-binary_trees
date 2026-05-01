#include "binary_trees.h"

/**
 * bst_insert - inserts into BST.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *parent, *new;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;
	parent = NULL;

	while (current)
	{
		parent = current;

		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (NULL);
	}

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (value < parent->n)
		parent->left = new;
	else
		parent->right = new;

	return (new);
}
