#include "set.h"
#include <stdio.h>

void Set :: printSet()
{
	int i = 0;

	printf("\nPrinting set.\n");
	if( size == 0 )
		printf("{ Empty Set }\n\n");
	else
	{
		printf("{ %d", set[i]);
		i++;

		for( i = i; i < size; i++ )
			printf(", %d", set[i]);

		printf(" }\n\n");
	}

}
