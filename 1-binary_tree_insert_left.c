#include "binary_trees.h"

/**
 * binary_tree_insert_left - it Inserts a node as the left child
 * @parent: Pointer to the node to insert the left-child in
 * @value: its the value to store in the new node
 *
 * Return: Pointer to node or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *former_left_child = NULL;
	binary_tree_t *new_left_child = NULL;

	if (parent == NULL)
		return (NULL);

	new_left_child = binary_tree_node(parent, value);
	if (new_left_child == NULL)
		return (NULL);

	if (parent->left != NULL)
		former_left_child = parent->left;

	parent->left = new_left_child;
	if (former_left_child)
	{
		new_left_child->left = former_left_child;
		former_left_child->parent = new_left_child;
	}

	return (new_left_child);
}
