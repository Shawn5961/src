#include "set.h"
#include <stdio.h>

//Search function for the set.
//Pre-condition:	A set, and a value to search for.
//Post-condition:	A boolean true or false
bool Set :: searchSet(int value)
{
	int i;

	//Iterates through the set, and if the input value is found, returns true.
	for( i = 0; i < size; i++ )
	{
		if( value == set[i] )
			return true;
	}

	//If the entire set has been iterated through, and input is not found, returns false
	return false;
}
