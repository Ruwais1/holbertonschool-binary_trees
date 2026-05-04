#include "binary_trees.h"

/**
 * check_avl - Helper function to check if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the node with the minimum allowed value
 * @max: Pointer to the node with the maximum allowed value
 * @height: Pointer to store the height of the tree
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int check_avl(const binary_tree_t *tree, const binary_tree_t *min,
	      const binary_tree_t *max, int *height)
{
	int h1 = 0, h2 = 0;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}

	if ((min && tree->n <= min->n) || (max && tree->n >= max->n))
		return (0);

	if (!check_avl(tree->left, min, tree, &h1) ||
	    !check_avl(tree->right, tree, max, &h2))
		return (0);

	*height = (h1 > h2 ? h1 : h2) + 1;

	if ((h1 > h2 ? h1 - h2 : h2 - h1) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	return (check_avl(tree, NULL, NULL, &height));
}
