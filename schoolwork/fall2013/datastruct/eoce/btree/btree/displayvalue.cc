#include "btree.h"

Node *Btree :: displayValue(int value, Node *branch)
{
	if( branch != NULL )
	{
		if( value == branch->getValue() )
			return branch;
		else if( value < branch->getValue() )
			return displayValue(value, branch->getPrev());
		else
			return displayValue(value, branch->getNext());
	}
	else
		return NULL;
}
