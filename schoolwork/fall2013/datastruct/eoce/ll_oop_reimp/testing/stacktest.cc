#include <stdio.h>
#include "stack.h"

int main()
{
	Node *tmp = new Node;
	Stack *myStack = new Stack(3);
	tmp -> setValue(fgetc(stdin));
	fgetc(stdin);

	while(tmp->getValue() != '\n')
	{
		myStack -> push(tmp);
		tmp = new Node(fgetc(stdin));
		fgetc(stdin);
	}

	fprintf(stdout, "linked list has %d nodes\n", myStack -> getListSize());
	fprintf(stdout, "String is: ");

	tmp = myStack -> pop();
	while (tmp != NULL)
	{
		fprintf(stdout, "%c", tmp -> getValue());
		delete tmp;
		tmp = myStack -> pop();
	}
	while(tmp != NULL);

	fprintf(stdout, "\n");
	return(0);
}
