#include "queue.h"

Node * Queue :: dequeue()
{
	Node *tmp;

	tmp = this->data->getNode(this->front);
	this->front = this->data->getEnd();

	return tmp;
}
