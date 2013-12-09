#include "list.h"

int List :: getQuantity()
{
	Node *tmp;
	int qty = 0;

	tmp = this -> start;

	while (tmp != NULL)
	{
		qty++;
		tmp = tmp -> getNext();
	}
	
	return qty;
}
