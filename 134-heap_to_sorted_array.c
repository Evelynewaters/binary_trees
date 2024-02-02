#include "binary_trees.h"

/**
 * tree_size - it measures the sum of heights of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: Height or 0 if tree is NULL.
 *
 * This function calculates the sum of heights of a binary tree by recursively
 * measuring the heights of the left and right subtrees and summing them.
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}

/**
 * heap_to_sorted_array - it converts a Binary Max Heap
 * to a sorted array of integers.
 * @heap: A pointer to the root node of the heap to convert.
 * @size: An address to store the size of the array.
 *
 * Return: The generated array or NULL on failure.
 *
 * The caller is responsible for freeing the allocated memory for the array.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);

	return (a);
}
