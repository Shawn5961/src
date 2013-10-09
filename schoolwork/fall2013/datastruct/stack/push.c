#include "stack.h"

void push(Stack **myStack, Node *newNode)
{
	if( (*myStack)->size >= (*myStack->data->qty))
	{
		(*myStack)->data = append((*myStack)->data, (*myStack)->data->end, newNode);
		(*myStack)->top = (*myStack)->data->end;
	}
}
