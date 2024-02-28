#include "binary_trees.h"

/**
 * bst_remove - Removes node with a specific value from Binary Search Tree
 * @root: Pointer to the root node of the BST
 * @value: Value to remove from the BST
 *
 * Return: Pointer to the new root node of the BST after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);

	}

	return (root);
}
