#include "list.h"

void List :: append(Node *place, Node *newNode)
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
		else if (place == this -> end)
		{
			this    -> end -> setNext(newNode);
			newNode -> setPrev(this->end);
			this->end = newNode;
		}
		else
		{
			newNode -> setPrev(place);
			if (place != NULL)
			{
				newNode -> setNext(place -> getNext());
				place   -> setNext(newNode);
				tmp = newNode -> getNext();
				tmp -> setPrev(newNode);
			}
		}
		this -> qty = this -> qty + 1;
	}
}
