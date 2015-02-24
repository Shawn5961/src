#include "node.h"

Node * Node :: getNext()
{
	return this->next;
}

void Node :: setNext(Node *next)
{
	this -> next = next;
}
