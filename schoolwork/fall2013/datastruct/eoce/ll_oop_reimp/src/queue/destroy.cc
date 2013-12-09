#include "queue.h"

Queue :: ~Queue()
{
	delete this -> data;
	this -> data   = NULL;
	this -> bufsiz = 0;
	this -> front  = NULL;
	this -> back   = NULL;
}
