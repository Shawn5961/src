#include "queue.h"
#include <stdio.h>

void Queue :: enqueue(Node *newNode)
{
	if( (this->bufsiz > 0) && ((this->data->getQuantity()) < (this->bufsiz)) )
	{
		this->data->insert(this->data->getStart(), newNode);
		this->back = this->data->getStart();
		this->front = this->data->getEnd();
	}
	else
		printf("Queue overload, not adding.");
}
