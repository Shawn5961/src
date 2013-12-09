#include "set.h"
#include <stdio.h>

void Set :: printSortedSet()
{
	int i, counter, temp;

	counter = size;

	do
	{
		for( i = 0; i < (counter - 1); i++ )
		{
			if( set[i] > set[i+1] )
			{
				temp = set[i];
				set[i] = set[i+1];
				set[i+1] = temp;
			}
		}

		counter--;
	} while( counter > 1 );

	i = 0;
	printf("\nSet successfully sorted. Printing sorted set.\n");
	printf("{ %d", set[i]);
	i++;

	for( i = i; i < size; i++ )
		printf(", %d", set[i]);

	printf(" }\n\n");
}

void Set :: printReverseSortedSet()
{
	int i, counter, temp;

	counter = size;

	do
	{
		for( i = 0; i < (counter - 1); i++ )
		{
			if( set[i] < set[i+1] )
			{
				temp = set[i];
				set[i] = set[i+1];
				set[i+1] = temp;
			}
		}

		counter--;
	} while( counter > 1 );

	i = 0;
	printf("\nSet successfully sorted. Printing sorted set.\n");
	printf("{ %d", set[i]);
	i++;

	for( i = i; i < size; i++ )
		printf(", %d", set[i]);

	printf(" }\n\n");
}
