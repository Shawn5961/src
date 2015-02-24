#include "stack.h"

Stack :: Stack()
{
	List *myList = new List();
	this->data = myList;
	this->top = this->data->getEnd();
	this->size = 0;
}

Stack :: Stack(int size)
{
	List *myList = new List();
	this->data = myList;
	this->top = this->data->getEnd();
	this->size = size;
}
