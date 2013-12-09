#include "set.h"
#include <stdio.h>
#include <math.h>

//Print super set function
void Set :: printSuperSet()
{
	int addedValue;

	//Instead of prompting for user input, adds a random value to the set.
	printf("Generating a random value between 0 and 99 to add to super set\n");
	addedValue = rand() % 100;

	printf("Attempting to add value: %d\n", addedValue);

	//Calls the searchSet function to assess if the set contains the value. If
	//it does not, the size is increased by 1, and the last value is set to
	//the value to be added
	if( searchSet(addedValue) == false )
	{
		this->size = size + 1;
		set[size-1] = addedValue;
		printf("Value successfully added to superset\n");
	}
	else
		printf("Value already exists. Not adding to superset.\n");
}
