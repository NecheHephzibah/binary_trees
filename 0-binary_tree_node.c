#include "binary_trees.h"

/**
  * binary_tree_node - function that creates a binary tree.
  * @parent: The parent of the tree.
  * @value: The value in the node created.
  * Return: a pointer to the new node, or NULL on failure.
  */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	return (node);
}
