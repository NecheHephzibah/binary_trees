#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int front = 0;
	int back = 0;
	int i = 0;
	const binary_tree_t *tmp;
	const binary_tree_t **queue;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);

	queue[back++] = tree;
	while (front < back)
	{
		tmp = queue[front++];
		if (tmp == NULL)
			i = 1;
		else
		{
			if (i == 1)
			{
				free(queue);
				return (0);
			}
			queue[back++] = tmp->left;
			queue[back++] = tmp->right;
		}
	}
	free(queue);
	return (1);
}
