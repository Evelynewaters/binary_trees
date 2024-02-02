#include "binary_trees.h"

/**
 * is_bst_helper - Helper function for binary_tree_is_bst
 * @node: Node to check
 * @min_val: Minimum value allowed in the subtree rooted at 'node'
 * @max_val: Maximum value allowed in the subtree rooted at 'node'
 *
 * Return: 1 if 'node' is part of a valid binary search tree (BST)
 *
 * This is a helper function used by binary_tree_is_bst to recursively check
 * if the binary tree is a valid binary search tree.
 */
int is_bst_helper(const binary_tree_t *node, int min_val, int max_val)
{
	if (node == NULL)
		return (1);

	if (node->n <= min_val || node->n >= max_val)
		return (0);

	return (is_bst_helper(node->left, min_val, node->n) &&
		   is_bst_helper(node->right, node->n, max_val));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree (BST).
 * @tree: Binary tree to check
 *
 * Return: 1 if 'tree' is a valid BST, 0 otherwise. If 'tree' is NULL, returns
 *          0.
 *
 * This function checks if the given binary tree is a valid binary search tree
 * (BST).
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
