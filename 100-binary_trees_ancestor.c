#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes,
 * or NULL if no common ancestor was found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *checker1 = (binary_tree_t *)first;
	binary_tree_t *checker2;

	if (first == NULL || second == NULL)
		return (NULL);

	while (checker1)
	{
		checker2 = (binary_tree_t *)second;
		while (checker2)
		{
			if (checker2 == checker1)
				return (checker1);
			checker2 = checker2->parent;
		}
		checker1 = checker1->parent;
	}
	return (NULL);
}
