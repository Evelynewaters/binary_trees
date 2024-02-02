#include "binary_trees.h"

/**
 * bst_search - it searches for a value in a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the tree.
 *
 * Return: A pointer to the node containing an int equal to 'value',
 *         NULL if 'tree' is NULL,
 *         NULL if no match is found.
 *
 * This function searches for a given value in a binary search tree (BST).
 * If 'tree' is NULL, it returns NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (node)
	{
		if (value == node->n)
			return (node);

		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
	}

	return (NULL);
}
