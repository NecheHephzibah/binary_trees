#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a
 * right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *fulcrum;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	fulcrum = tree->left;
	tree->left = fulcrum->right;

	if (fulcrum->right != NULL)
		fulcrum->right->parent = tree;

	fulcrum->right = tree;

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = fulcrum;
		else
			tree->parent->right = fulcrum;
	}

	fulcrum->parent = tree->parent;
	tree->parent = fulcrum;

	return (fulcrum);
}
