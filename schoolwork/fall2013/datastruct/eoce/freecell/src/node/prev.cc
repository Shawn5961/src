#include "node.h"

Node * Node :: getPrev()
{
	return (this -> prev);
}

void Node :: setPrev(Node *prev)
{
	this->prev = prev;
}
