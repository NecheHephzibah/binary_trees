#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  function that performs a
 * left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *fulcrum;

	if (tree == NULL || tree->right == NULL)
		return (tree); 
	
	fulcrum = tree->right;
	tree->right = fulcrum->left;

	if (fulcrum->left != NULL)
		fulcrum->left->parent = tree;

	fulcrum->left = tree;

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
