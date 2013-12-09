#include "set.h"
#include <stdio.h>

int Set :: modSet()
{
	int i, result = 0;

	for( i = 0; i < size; i++ )
		result += set[i];

	result = result % size;

	return result;
}

int Set :: modSet(int input)
{
	int i, result = 0;

	for( i = 0; i < size; i++ )
		result += set[i];

	result = result % input;

	return result;
}
