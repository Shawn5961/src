#include "stack.h"

Stack *mkstack(int size)
{
	Stack *myStack;

	myStack = (Stack *) malloc (sizeof(Stack));

	myStack -> data = mklist();
	myStack -> size = size;
	myStack -> top  = myStack -> data -> end;

	return (myStack);
}
