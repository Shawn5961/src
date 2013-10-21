#include <stdio.h>
#include "stack.h"

int main()
{
	Node *tmp;
	Stack *myStack;
	myStack = mkstack(0);
	tmp = create();
	tmp -> value = fgetc(stdin);
	fgetc(stdin);

	while(tmp->value != '\n')
	{
		myStack = push(myStack, tmp);
		tmp = create();
		tmp->value = fgetc(stdin);
		fgetc(stdin);
	}

	fprintf(stdout, "linked list has %d nodes\n", myStack->data->qty);
	fprintf(stdout, "String is: ");
	do {
		tmp = pop(&myStack);
		if(tmp != NULL)
		{
			fprintf(stdout, "%c", tmp->value);
		}
		rmnode(*tmp);
	}
	while(tmp != NULL);

	fprintf(stdout, "\n");
	return(0);
}
