#include "node.h"

Node :: ~Node()
{
	this -> next  = NULL;
	this -> prev  = NULL;
	if (this -> data != NULL)
		delete this -> data;

	this -> data  = NULL;
	this -> value = 0;
	this->suit = 0;
}
