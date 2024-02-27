#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds lowest common ancestor of two nodes.
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: NULL on failure or the new node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *ancestor == NULL;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	ancestor = binary_trees_ancestor(first->left, second->left);

	if (ancestor != NULL)
	{
		return ((binary_tree_t *)ancestor);
	}
	
	ancestor = binary_trees_ancestor(first->right, second->right);

	if (ancestor != NULL)
	{
		return ((binary_tree_t *)ancestor);
	}

	if (binary_tree_descendant(first, second) || binary_tree_descendant(second, first))
	{
		return ((binary_tree_t *)first);
	}

	return (NULL);
}
