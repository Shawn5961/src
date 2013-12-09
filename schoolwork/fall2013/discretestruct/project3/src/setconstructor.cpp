#include "set.h"
#include <stdio.h>

//Constructor for the Set object.
Set :: Set()
{
	int input, i = 0;

	//Prompts the user to input the first set value
	printf("Enter a value (-1 to quit)\n");
	scanf("%d", &input);

	//Starts an input loop which will run until either the user enters -1, or
	//until the set has 99 values. This is set to be one less than the maximum
	//range of the set so as not to interfere with the superset functionality.
	while( input != -1 && i < 99)
	{
		this->set[i] = input;
		i++;
		if( i < 99 )
		{
			printf("Enter a value (-1 to quit)\n");
			scanf("%d", &input);
		}
		//If the user has entered the maximum number of values, the size will be
		//incorrect because of the way this loop runs. This will fix the size issue.
		else
			i--;
	};

	//Set the size variable to however many values the user entered
	this->size = i;

	//Start a loop at the current position of i, setting all uninitialized values
	//of the set to be -1.
	for( i = i; i < 100; i++ )
	{
		set[i] = -1;
	}
}
