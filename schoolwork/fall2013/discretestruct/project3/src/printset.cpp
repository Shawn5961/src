#include "set.h"
#include <stdio.h>

//Print function for the set.
void Set :: printSet()
{
	int i = 0;

	printf("\nPrinting set.\n");

	//If the set is of size 0, print that it is an empty set.
	if( size == 0 )
		printf("{ Empty Set }\n\n");
	//Loop through the set and print the values. The first value is
	//outside of the loop, for formatting reasons.
	else
	{
		printf("{ %d", set[i]);
		i++;

		for( i = i; i < size; i++ )
			printf(", %d", set[i]);

		printf(" }\n\n");
	}

}
