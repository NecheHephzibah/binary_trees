#include "binary_trees.h"


/**
  * binary_tree_insert_left - function that inserts a node to the left
  * of another node.
  * @parent: The pointer to the parent node.
  * @value: The value to store in the new node.
  * Return: a pointer to the new node, or NULL on failure or if
  * the parent os NULL.
  */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (parent == NULL)
		return (NULL);

	newnode = binary_tree_node(parent, value);

	if (newnode == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		newnode->left = parent->left;

		parent->left->parent = newnode;

	}
	parent->left = newnode;
	return (newnode);
}
