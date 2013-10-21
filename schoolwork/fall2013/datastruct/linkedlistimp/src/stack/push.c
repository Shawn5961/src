#include "stack.h"

Stack *push(Stack *myStack, Node *newNode)
{
	if ((myStack -> size <= 0) || ((myStack -> data -> qty) < (myStack -> size)))
	{
		myStack -> data = append(myStack -> data, myStack -> data -> end, newNode);
		myStack -> top  = myStack -> data -> end;
	}

	return(myStack);
}
