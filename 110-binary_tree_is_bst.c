#include "binary_trees.h"


/**
 * bst_helper - helper function for binary_tree_is_bst
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value that current node can take
 * @max: maximum value that current node can take
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_search_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (binary_search_helper(tree->left, min, tree->n - 1)
			&& binary_search_helper(tree->right, tree->n + 1, max));
}


/**
 * binary_tree_is_bst - checks if a binary tree is a valid
 * Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 * If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_search_helper(tree, INT_MIN, INT_MAX));
}
