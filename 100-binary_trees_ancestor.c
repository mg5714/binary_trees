#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds lowest common ancestor of two nodes.
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: NULL on failure or the new node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *lt, *rt;

	if (tree == NULL || first == NULL || second == NULL)
	{
		return (NULL);
	}

	if (tree == first)
	{
		return ((binary_tree_t *)first);
	}

	if (tree == second)
	{
		return ((binary_tree_t *)second);
	}

	lt = binary_trees_ancestor(tree->left, first, second);
	rt = binary_trees_ancestor(tree->right, first, second);

	if (lt && rt)
	{
		return ((binary_tree_t *)tree);
	}

	return (lt ? lt : rt);
}
