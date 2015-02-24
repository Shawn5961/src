#include "queue.h"

int Queue :: getBufferSize()
{
	return this->bufsiz;
}

void Queue :: setBufferSize(int size)
{
	this->bufsiz = size;
}
