#include "stack.h"

void Stack :: push(Node *newNode)
{

	if( (this->size > 0) && ((this->data->getQuantity()) < (this->size)) )
	{
		this->data->insert(this->data->getEnd(), newNode);
		this->top = this->data->getEnd();
	}
}
