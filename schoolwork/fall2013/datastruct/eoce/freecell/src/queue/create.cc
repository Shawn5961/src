#include "queue.h"

Queue :: Queue()
{
	List *myList = new List();
	this->data = myList;
	this->front = this->data->getEnd();
	this->back = this->data->getStart();
	this->bufsiz = 0;
}

Queue :: Queue(int size)
{
	List *myList = new List();
	this->data = myList;
	this->front = this->data->getEnd();
	this->back = this->data->getStart();
	this->bufsiz = size;
}
