#include "btree.h"
#include <stdio.h>

Node *mkNode(int value)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

Node* insert(int value, Node *branch)
{
	if( branch != NULL )
	{
		if( value <= branch->value )
			branch->left = insert(value, branch->left);
		else if( value > branch->value )
			branch->right = insert(value, branch->right);
	}
	else
		return mkNode(value);

	return(branch);
}

Node* search(int value, Node *branch)
{
	if( branch != NULL )
	{
		if( value == branch->value )
			return branch;
		else if( value < branch->value )
			return search(value, branch->left);
		else
			return search(value, branch->right);
	}
	else
		return NULL;
}

void remove(int value, Node *branch)
{
	if( branch != NULL )
	{
		if( value == branch->value )
			free(branch);
		else if( value < branch->value )
			remove(value, branch->left);
		else
			remove(value, branch->right);
	}
}

void displayTree(Node *branch)
{
	if( branch != NULL )
	{
		displayTree(branch->left);
		displayTree(branch->right);

		printf("%d ", branch->value);
	}
}

void displayValue(Node *branch)
{
	if( branch != NULL )
	{
		displayValue(branch->left);
		printf("%d ", branch->value);
		displayValue(branch->right);
	}
}
