#include "stack.h"

Node * Stack :: pop()
{
	Node *tmp;
	
	tmp = this->data->getNode(this->top);
	this->top = this->data->getEnd();

	return tmp;
}
