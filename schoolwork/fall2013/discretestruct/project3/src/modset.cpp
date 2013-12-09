#include "set.h"
#include <stdio.h>

//Modulus operation for the set.
//Default modulus
//Pre-condition:	A set of values
//Post-Condition:	The modulus of a set of values, using the set size as an operator
int Set :: modSet()
{
	int i, result = 0;

	//Add together the values in the set to get a total.
	for( i = 0; i < size; i++ )
		result += set[i];

	//Mod the set by the size of the set
	result = result % size;

	return result;
}

//User-defined modulus
//Pre-condition:	A set of values, and a user defined modulus operator
//Post-Condition:	The modulus of a set of values, using the user defined operator
int Set :: modSet(int input)
{
	int i, result = 0;

	//Add together the values in the set to get a total.
	for( i = 0; i < size; i++ )
		result += set[i];

	//Mod by the user's input to the function
	result = result % input;

	return result;
}
