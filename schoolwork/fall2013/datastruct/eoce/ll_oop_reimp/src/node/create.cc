#include "node.h"

Node :: Node()
{
	this -> next  = NULL;
	this -> prev  = NULL;
	this -> data  = NULL;
	this -> value = 0;
}

Node :: Node(int value)
{
	this -> next  = NULL;
	this -> prev  = NULL;
	this -> data  = NULL;
	this -> value = value;
}
