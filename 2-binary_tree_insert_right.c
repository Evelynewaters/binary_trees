#include "binary_trees.h"

/**
 * binary_tree_insert_right - it Inserts a node as the right child
 * @parent: Pointer to the node to insert the right-child
 * @value: The value to store in the new node
 *
 * Return: Pointer to the node or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *former_right_child = NULL;
	binary_tree_t *new_right_child = NULL;

	if (parent == NULL)
		return (NULL);

	new_right_child = binary_tree_node(parent, value);
	if (new_right_child == NULL)
		return (NULL);

	if (parent->right != NULL)
		former_right_child = parent->right;

	parent->right = new_right_child;
	if (former_right_child)
	{
		new_right_child->right = former_right_child;
		former_right_child->parent = new_right_child;
	}

	return (new_right_child);
}
