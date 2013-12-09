#include "set.h"
#include <stdio.h>
#include <algorithm>

//Recursive function to print set permutations
//The function is initialized with var k equal to the size of the set.
void Set :: printSetPerm(int k)
{
	int i, temp;

	//Base case for the recursive function
	if( k == 0 )
		printSet();
	else
	{
		//Runs a swap operation, calls the recursive printSetPerm function,
		//then runs a second swap operation.
		for( i = k - 1; i >= 0; i-- )
		{
			temp = set[i];
			set[i] = set[k - 1];
			set[k - 1] = temp;

			printSetPerm(k - 1);

			temp = set[i];
			set[i] = set[k - 1];
			set[k - 1] = temp;
		}
	}

}
