#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int back = 0;
	int front = 0;
	const binary_tree_t *tmp;
	const binary_tree_t ** queue;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (queue == NULL)
		return;

	queue[back++] = tree;
	while (front < back)
	{
		tmp = queue[front++];
		func(tmp->n);

		if (tmp->left != NULL)
			queue[back++] = tmp->left;
		if (tmp->right != NULL)
			queue[back++] = tmp->right;
	}
	free(queue);
}
