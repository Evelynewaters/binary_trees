#include "binary_trees.h"

/**
 * count_height - it recursively measures the height of a binary tree
 * @tree: A pointer to a tree node
 * @height: The current height of the tree being traversed
 * @max: A pointer to the maximum height found so far
 *
 * This is a helper function used by binary_tree_height to traverse the binary
 * tree recursively and calculate the height of the tree. It updates the 'max'
 * variable with the maximum height found during traversal.
 */
void count_height(const binary_tree_t *tree, size_t height, size_t *max)
{
	if (tree)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			if (height > *max)
			{
				*max = height;
			}
		}
		else
		{
			count_height(tree->left, height + 1, max);
			count_height(tree->right, height + 1, max);
		}
	}
}

/**
 * binary_tree_height - It measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If 'tree' is NULL, returns 0.
 *
 * This function calculates the height of a binary tree by finding the longest
 * path from the root node to any leaf node. It does this by calling the
 * count_height function recursively, which updates the 'max_height' variable.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t max_height = 0;

	count_height(tree, 0, &max_height);

	return (max_height);
}
