#include "stack.h"

Stack *mkstack(int size)
{
	Stack *myStack;
	myStack = (Stack*)malloc(sizeof(Stack));
	myStack->size = size;
	myStack->data = mklist();
	myStack->top = myStack->data->end;

	return(myStack);
}
