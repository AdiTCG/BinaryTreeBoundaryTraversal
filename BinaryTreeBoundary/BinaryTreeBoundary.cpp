// BinaryTreeBoundary.cpp : Defines the entry point for the console application.
//
/* program for boundary traversal of a binary tree */
#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#pragma region define node
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node *left, *right;
};

#pragma endregion

#pragma region print leaves

// A simple function to print leaf nodes of a binary tree
void printLeaves(struct node* root)
{
	if (root)
	{
		printLeaves(root->left);

		// Print it if it is a leaf node
		if (!(root->left) && !(root->right))
			printf("%d ", root->data);

		printLeaves(root->right);
	}
}

#pragma endregion

#pragma region print boundary left

// A function to print all left boundry nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft(struct node* root)
{
	if (root)
	{
		if (root->left)
		{
			// to ensure top down order, print the node
			// before calling itself for left subtree
			printf("%d ", root->data);
			printBoundaryLeft(root->left);
		}
		else if (root->right)
		{
			printf("%d ", root->data);
			printBoundaryLeft(root->right);
		}
		// do nothing if it is a leaf node, this way we avoid
		// duplicates in output
	}
}
#pragma endregion

#pragma region print boundar right

// A function to print all right boundry nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(struct node* root)
{
	if (root)
	{
		if (root->right)
		{
			// to ensure bottom up order, first call for right
			//  subtree, then print this node
			printBoundaryRight(root->right);
			printf("%d ", root->data);
		}
		else if (root->left)
		{
			printBoundaryRight(root->left);
			printf("%d ", root->data);
		}
		// do nothing if it is a leaf node, this way we avoid
		// duplicates in output
	}
}
#pragma endregion

#pragma region print boundary

// A function to do boundary traversal of a given binary tree
void printBoundary(struct node* root)
{
	if (root)
	{
		printf("%d ", root->data);

		// Print the left boundary in top-down manner.
		printBoundaryLeft(root->left);

		// Print all leaf nodes
		printLeaves(root->left);
		printLeaves(root->right);

		// Print the right boundary in bottom-up manner
		printBoundaryRight(root->right);
	}
}
#pragma endregion

#pragma region create new node

// A utility function to create a node
struct node* newNode(int data)
{
	struct node* temp = (struct node *) malloc(sizeof(struct node));

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}
#pragma endregion

#pragma region main

int main()
{
	// Let us construct the tree given in the above diagram
	struct node *root = newNode(1);

	root->left = newNode(11);
	root->left->left = newNode(111);
	root->left->left->left = newNode(1111);
	root->left->left->right = newNode(1110);
	root->left->left->left->left = newNode(11111);

	root->left->left->left->right = newNode(11110);

	printBoundary(root);

	return 0;
}
#pragma endregion