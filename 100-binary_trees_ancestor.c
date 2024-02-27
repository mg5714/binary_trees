#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds lowest common ancestor of two nodes.
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: NULL on failure or the new node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *temp1, *temp2;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	temp1 = first;
	while (temp1 != NULL)
	{
		temp2 = second;
		while (temp2 != NULL)
		{
			if (temp1 == temp2)
				return ((binary_tree_t *)temp1);
			temp2 = temp2->parent;
		}
		temp1 = temp1->parent;
	}

	return (NULL);
}
