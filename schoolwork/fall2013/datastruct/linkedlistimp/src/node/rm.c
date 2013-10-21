#include "node.h"

void rmnode(Node **tmp)
{
	if ((*tmp) -> prev != NULL)
	{
		(*tmp) -> prev -> next = (*tmp) -> next;
	}

	if ((*tmp) -> next != NULL)
	{
		(*tmp) -> next -> prev = (*tmp) -> prev;
	}

	(*tmp) -> prev  = (*tmp) -> next = NULL;
}
