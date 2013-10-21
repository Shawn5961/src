#include "node.h"

Node *cpnode(Node *tmp)
{
	Node *newNode = mknode(tmp -> value);

	newNode -> prev = newNode -> next = NULL;

	return(newNode);
}
