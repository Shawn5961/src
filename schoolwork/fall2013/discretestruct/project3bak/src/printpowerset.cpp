#include "set.h"
#include <stdio.h>
#include <math.h>

void Set :: printPowerSet()
{
	int i, j, powerSetSize;

	powerSetSize = pow(2, size);

	printf("\n!! PRINTING POWER SET !!\n");

	printf("{ Empty Set }");
	for( i = 0; i < powerSetSize; i++ )
	{
		for( j = 0; j < size; j++ )
		{
			if( i & (1<<j))
				printf("%d ", set[j]);
		}

		printf("\n");
	}

}
