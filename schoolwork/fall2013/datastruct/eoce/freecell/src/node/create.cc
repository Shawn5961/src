#include "node.h"

Node :: Node()
{
	this -> next  = NULL;
	this -> prev  = NULL;
	this -> data  = NULL;
	this -> value = 0;
	this->suit = 0;
}

Node :: Node(int value, char suit)
{
	this -> next  = NULL;
	this -> prev  = NULL;
	this -> data  = NULL;
	this -> value = value;
	this->suit = suit;
}
