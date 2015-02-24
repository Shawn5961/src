#include "btree.h"

Btree :: ~Btree()
{
	removeValue(root);
}
