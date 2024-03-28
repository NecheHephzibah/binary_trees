#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the binary tree, or 0 if tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left_tree = 0;
	size_t height_right_tree = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		height_left_tree = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		height_right_tree = 1 + binary_tree_height(tree->right);
	if (height_left_tree > height_right_tree)
		return (height_left_tree);
	else
		return (height_right_tree);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_left_tree = 0;
	int height_right_tree = 0;

	if (tree == NULL)
	{
		return (0);
	}

	height_left_tree = binary_tree_height(tree->left);
	height_right_tree = binary_tree_height(tree->right);

	if (height_left_tree == height_right_tree)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			return (1);
		}
		if (tree->left != NULL && tree->right != NULL)
		{
			return (binary_tree_is_perfect(tree->left) &&
					binary_tree_is_perfect(tree->right));
		}
	}

	return (0);
}
