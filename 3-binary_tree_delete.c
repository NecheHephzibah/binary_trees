#include "binary_trees.h"

/**
  * binary_tree_delete - function that deletes a binary tree
  * @tree: Pointer to the root node of tree to delete
  * Return: void
  */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	else
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
