#include "btree.h"

void Btree :: insert(int input, Node *branch)
{
	Node *tmp = new Node(input);

	if( input < branch->getValue() )
	{
		if( branch->getPrev() != NULL )
		{
			insert(input, branch->getPrev());
		}
		else
		{
			branch->setPrev(tmp);
			branch->getPrev()->setPrev(NULL);
			branch->getPrev()->setNext(NULL);
		}
	}
	else if( input >= branch->getValue() )
	{
		if( branch->getNext() != NULL )
		{
			insert(input, branch->getNext());
		}
		else
		{
			branch->setNext(tmp);
			branch->getNext()->setPrev(NULL);
			branch->getNext()->setNext(NULL);
		}
	}
}
