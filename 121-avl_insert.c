#include "binary_trees.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to root node of the AVL tree for inserting value
 * @value: Value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
	}
	else if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (NULL);
	}

	(*tree)->parent = (*tree)->parent;
	binary_tree_balance(*tree);
	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
	{
		return (binary_tree_rotate_right(*tree));
	}
	if (balance < -1 && value > (*tree)->right->n)
	{
		return (binary_tree_rotate_left(*tree));
	}
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}
