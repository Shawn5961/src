#include "set.h"
#include <stdio.h>
#include <math.h>

void Set :: printSuperSet()
{
	int addedValue;

	printf("Generating a random value between 0 and 99 to add to super set\n");
	addedValue = rand() % 100;

	printf("Attempting to add value: %d\n", addedValue);

	if( searchSet(addedValue) == false )
	{
		this->size = size + 1;
		set[size-1] = addedValue;
		printf("Value successfully added to superset\n");
	}
	else
		printf("Value already exists. Not adding to superset.\n");
}
