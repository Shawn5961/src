#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *push(Stack *myStack, Node *newNode)
{
	if ((myStack -> size > 0) && ((myStack -> data -> qty) < (myStack -> size)))
	{
		myStack -> data = insert(myStack -> data, myStack -> data -> end, newNode);
		myStack -> top  = myStack -> data -> end;
	}

	return(myStack);
}
