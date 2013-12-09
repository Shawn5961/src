#include "set.h"
#include <stdio.h>
#include <math.h>

//Function to print the power set of the Set
void Set :: printPowerSet()
{
	int i, j, powerSetSize;

	//Calculate the number of sets within the set by raising 2 to the size power
	powerSetSize = pow(2, size);

	printf("\n!! PRINTING POWER SET !!\n");

	
	//Loop to print the power set, using bitwise operations to print values of the set.
	//The left shift is used to print the set in a somewhat logical order. If there is 
	//a 1 contained in a position of the set, that value is printed.
	//Example: For set {1, 2, 3}, bits 101 would print power set {1, 3}
	for( i = 0; i < powerSetSize; i++ )
	{
		printf("{ ");

		//The first time the loop runs, all the bits will be 0, so nothing will be
		//printed. In this case, we print the string "empty set"
		if( i == 0 )
			printf("Empty Set");
		for( j = 0; j < size; j++ )
		{
			if( i & (1 << j) )
				printf("%d ", set[j]);
		}

		printf("}\n");
	}

}
