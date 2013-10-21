#include <stdio.h>
#include "stack.h"

int main()
{
	Node *tmp;
	Stack *myStack;
	myStack = mkstack(0);

	tmp = mknode(fgetc(stdin));
	fgetc(stdin);
	while(tmp->value != '\n')
	{
		myStack = push(myStack, tmp);
		tmp = mknode(fgetc(stdin));
		fgetc(stdin);
	}

	printf("Linked list has %d nodes\n", myStack->data->qty);

	printf("String is: ");
	do
	{
		tmp = pop(&myStack);
		if( tmp != NULL )
			printf("%c", tmp->value);
	} while( tmp != NULL );

	printf("\n");

	return 0;
}
