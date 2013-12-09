#include "stack.h"

Node * Stack :: peek()
{
	Node *tmp;
	tmp = this->pop();
	this->push(tmp);
}
