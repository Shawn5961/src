#include "list.h"

Node * List :: getNode (Node *place)
{
	if( place == this->start )
	{
		this->start = this->start->getNext();
		this->start->setPrev(NULL);
		place->setNext(NULL);
	}
	else if( place == this->end )
	{
		this->end = this->end->getPrev();
		this->end->setNext(NULL);
		place->setPrev(NULL);
	}
	else
	{
		place->getPrev()->setNext(place->getNext());
		place->getNext()->setPrev(place->getPrev());
		place->setPrev(NULL);
		place->setNext(NULL);
	}
	
	this->qty = this->qty - 1;
	
	return place;
}
