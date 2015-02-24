#include <stdio.h>
#include "queue.h"

int main()
{
	Node *tmp = new Node;
	Queue *myQueue = new Queue(3);
	tmp -> setValue(fgetc(stdin));
	fgetc(stdin);

	while(tmp->getValue() != '\n')
	{
		myQueue -> enqueue(tmp);
		tmp = new Node(fgetc(stdin));
		fgetc(stdin);
	}

	fprintf(stdout, "linked list has %d nodes\n", myQueue -> getBufferSize());
	fprintf(stdout, "String is: ");

	tmp = myQueue -> dequeue();
	while (tmp != NULL)
	{
		fprintf(stdout, "%c", tmp -> getValue());
		delete tmp;
		tmp = myQueue -> dequeue();
	}
	

	fprintf(stdout, "\n");
	return(0);
}
