#include "binary_trees.h"

int comparison(const void *a, const void *b);
bst_t *helper_to_bst(int *array, int start, int end);

/**
  * comparison - function that compares and sorts values.
  * @a: first value to be compared.
  * @b: second value to be compared.
  * Return: returns the difference.
  */

int comparison(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

/**
 * helper_to_bst - function to recursively build a Binary
 * Search Tree from an array.
 * @array: Pointer to the array to be built upon.
 * @start: Where the array starts from.
 * @end: Where the array ends.
 */
bst_t *helper_to_bst(int *array, int start, int end)
{
	bst_t *root;
	int mid;

	if (start > end)
		return NULL;

	mid = (start + end) / 2;

	root = binary_tree_node(NULL, array[mid]);
	if (root == NULL)
		return NULL;

	root->left = helper_to_bst(array, start, mid - 1);
	root->right = helper_to_bst(array, mid + 1, end);

	return root;
}

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
 	if (array == NULL || size == 0)
		return NULL;

	qsort(array, size, sizeof(int), comparison);

	return helper_to_bst(array, 0, size - 1);
}

