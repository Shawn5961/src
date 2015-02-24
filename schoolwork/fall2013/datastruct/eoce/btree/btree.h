#ifndef _BTREE_H
#define _BTREE_H

#include <stdlib.h>

struct node{
	int value;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

Node *mkNode(int);
Node *insert(int, Node*);
void remove(int, Node*);
Node *search(int, Node*);
void displayTree(Node*);
void displayValue(Node*);

#endif
