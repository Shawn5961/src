#include "set.h"
#include <stdio.h>

void Set :: buildSet()
{
	int input, i = 0;

	printf("Enter a value (-1 to quit)\n");
	scanf("%d", &input);

	while( input != -1 && i < 100)
	{
		this->set[i] = input;
		i++;
		printf("Enter a value (-1 to quit)\n");
		scanf("%d", &input);
	};

	this->size = i;

	for( i = i; i < 100; i++ )
	{
		set[i] = -1;
	}
}
