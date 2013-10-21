#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Node *pop(Stack **myStack)
{
	Node *tmp = NULL;

	if( myStack != NULL )
	{
		tmp = getNode((*myStack)->data, &(*myStack)->data->end);
		(*myStack)->top = (*myStack)->data->end;
	}
	return(tmp);
}
