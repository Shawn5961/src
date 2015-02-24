#include "list.h"

// insert() - insert newNode before place in this
//
void List :: insert(Node *place, Node *newNode)
{
	Node *tmp;
	if ((this != NULL) && (newNode != NULL))
	{
		if (this -> start == NULL)
		{
			this    -> start = this  -> end  = newNode;
			newNode -> setPrev(NULL);
			newNode -> setNext(NULL);
		}
		else if (place == this -> start)
		{
			this    -> start -> setPrev(newNode);
			newNode -> setNext(this -> start);
			this    -> start = newNode;
		}
		else
		{
			newNode -> setNext(place);
			if (place != NULL)
			{
				newNode -> setPrev(place -> getPrev());
				place   -> setPrev(newNode);
				tmp = newNode -> getPrev();
				tmp -> setNext(newNode);
			}
		}
		this -> qty = this -> qty + 1;
	}
}
