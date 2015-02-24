#include "stack.h"
#include <stdio.h>

void Stack :: push(Node *newNode)
{

	if( (this->size > 0) && ((this->data->getQuantity()) < (this->size)) )
	{
		this->data->append(this->data->getEnd(), newNode);
		this->top = this->data->getEnd();
	}
	else
	{
		printf("Stack overflow, not adding.");
	}
}
