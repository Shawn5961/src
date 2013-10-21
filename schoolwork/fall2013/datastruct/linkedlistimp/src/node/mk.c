#include "node.h"

Node *mknode(int value)
{
	Node *tmp = (Node *) malloc (sizeof(Node));

	tmp -> prev  = tmp -> next = NULL;
	tmp -> value =               value;

	return(tmp);
}
