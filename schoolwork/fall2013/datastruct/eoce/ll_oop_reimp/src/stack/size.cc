#include "stack.h"

int Stack :: getSize()
{
	return this->size;
}

void Stack :: setSize(int size)
{
	this -> size = size;
}

int Stack :: getListSize()
{
	return (this -> getQuantity());
}
