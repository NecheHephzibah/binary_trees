#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the binary tree, or 0 if tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left_tree, height_right_tree;

	if (tree == NULL)
		return (0);

	height_left_tree = binary_tree_height(tree->left);
	height_right_tree = binary_tree_height(tree->right);

	return ((height_left_tree > height_right_tree ?
			height_left_tree : height_right_tree) + 1);
}
