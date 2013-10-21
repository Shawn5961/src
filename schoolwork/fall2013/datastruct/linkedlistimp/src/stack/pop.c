#include "stack.h"

Node *pop(Stack **myStack)
{
	Node *tmp = NULL;

	if ((*myStack) != NULL)
	{
		tmp = (*myStack) -> data -> end;
		(*myStack) -> data = removeNode((*myStack) -> data, &tmp);
		(*myStack) -> top  = (*myStack) -> data -> end;
	}

	return (tmp);
}
