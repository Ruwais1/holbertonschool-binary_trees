#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * Description: Uses post-order traversal to safely free the memory.
 * If tree is NULL, the function does nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* 1. Delete the left subtree */
	binary_tree_delete(tree->left);

	/* 2. Delete the right subtree */
	binary_tree_delete(tree->right);

	/* 3. Delete the current node */
	free(tree);
}
