#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp_root;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}

	tmp_root = tree->left;
	tree->left = tmp_root->right;

	if (tmp_root->right != NULL)
	{
		tmp_root->right->parent = tree;
	}

	tmp_root->right = tree;
	tmp_root->parent = tree->parent;
	tree->parent = tmp_root;

	return (tmp_root);
}
