#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *peek(Stack *myStack)
{
	Node *tmp;
	tmp = pop(&myStack);
	push(myStack, tmp);

	return(myStack);
}
