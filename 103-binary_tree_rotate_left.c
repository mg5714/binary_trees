#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp_root;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}

	tmp_root = tree->right;
	tree->right = tmp_root->left;

	if (tmp_root->left != NULL)
	{
		tmp_root->left->parent = tree;
	}

	tmp_root->left = tree;
	tmp_root->parent = tree->parent;
	tree->parent = tmp_root;
	return (tmp_root);
}
