#include "set.h"
#include <stdio.h>
#include <algorithm>

void Set :: printSetPerm(int k, int setSize)
{
	int i, temp;

	if( k == 0 )
		printSet();
	else
	{
		for( i = k - 1; i >= 0; i-- )
		{
			temp = set[i];
			set[i] = set[k - 1];
			set[k - 1] = temp;

			printSetPerm(k - 1, setSize);

			temp = set[i];
			set[i] = set[k - 1];
			set[k - 1] = temp;
		}
	}

}
