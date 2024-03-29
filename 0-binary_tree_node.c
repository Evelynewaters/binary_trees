#include "binary_trees.h"

/**
 * binary_tree_node - it creates a binary tree node and initializes it.
 * @parent: Node's parent
 * @value: Node's value
 *
 * Return: Pointer to the node or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	return (new_node);
}
