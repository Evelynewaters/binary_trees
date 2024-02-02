#include "binary_trees.h"

/**
 * binary_tree_height - It measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If 'tree' is NULL, returns 0.
 *
 * This function calculates the height of a binary tree by finding the longest
 * path from the root node to any leaf node. It uses recursion to traverse the
 * binary tree and computes the height based on the heights of the left and
 * right subtrees.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		if (tree->right)
			right = 1 + binary_tree_height(tree->right);

		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}

/**
 * binary_tree_size - it measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: The number of nodes in the binary tree. If 'tree' is NULL, returns 0
 *
 * This function calculates the size of a binary tree by counting the number of
 * nodes in the tree. It uses recursion to traverse the binary tree and
 * computes the size based on the number of nodes in the left and right
 * subtrees.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t n_left, n_right;

	if (tree == NULL)
		return (0);

	n_left = binary_tree_size(tree->left);
	n_right = binary_tree_size(tree->right);

	return (1 + n_left + n_right);
}

/**
 * binary_tree_is_perfect - it checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise. If 'tree' is NULL, returns 0.
 *
 * A binary tree is considered perfect if all levels are fully filled (i.e., all
 * nodes at each level have two children) and the number of nodes in the tree is
 * equal to 2^(height + 1) - 1, where 'height' is the height of the binary tree.
 * This function checks if the given binary tree is perfect using the height and size.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h = 0, perfect_size = 0;

	if (tree == NULL)
		return (0);

	h = binary_tree_height(tree);

	perfect_size = (1 << (h + 1)) - 1;

	if (perfect_size == binary_tree_size(tree))
		return (1);
	else
		return (0);
}
