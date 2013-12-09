#include "set.h"
#include <stdio.h>

bool Set :: searchSet(int value)
{
	int i;

	for( i = 0; i < size; i++ )
	{
		if( value == set[i] )
			return true;
	}

	return false;
}
