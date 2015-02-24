#include "btree.h"

void Btree :: removeValue(Node *branch)
{
	if( branch != NULL )
	{
		removeValue(branch->getPrev());
		removeValue(branch->getNext());
		delete branch;
	}
}
