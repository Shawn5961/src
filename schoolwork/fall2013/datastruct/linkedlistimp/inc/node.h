#ifndef _NODE_H
#define _NODE_H

#include <stdlib.h>

struct node {
	struct node *next;
	struct node *prev;
	int value;
};
typedef struct node Node;

Node *mknode(int);
void  rmnode(Node **);
Node *cpnode(Node *);

#endif
