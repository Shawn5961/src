#include "stack.h"

Stack :: ~Stack()
{
	delete this -> data;
	this -> data  = NULL;
	this -> size  = 0;
	this -> top   = NULL;
}
