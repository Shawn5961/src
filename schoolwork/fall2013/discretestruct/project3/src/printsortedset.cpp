#include "set.h"
#include <stdio.h>

//Bubble sort functions for the set.
//Ascending sort
//Pre-condition:	A set of values.
//Post-condition:	A set of values sorted in ascending order
void Set :: printSortedSet()
{
	int i, counter, temp;

	//Set a counter equal to the size of the set
	counter = size;

	//Loop through the set, comparing a value to the value next to it.
	//If the value next to it is lower, they will be swapped. After
	//a value has been moved to it's rightmost position, the counter
	//decreases by 1.
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

	printSet();
}

//Descending sort
//This function is a copy of the first one, with the comparison in the loop
//changed from > to <
//Pre-condition:	A set of values.
//Post-condition:	A set of values sorted in descending order
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

	printSet();
}
