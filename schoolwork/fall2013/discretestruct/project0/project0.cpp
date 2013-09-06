/* Shawn Meas
 * Project 0 for Discrete Structures
 * Keyword given: Right Complementation
 */

#include <stdio.h>

int main()
{
	//Initialize int variables for p, q, and result.
	int p, q, result;

	//Initialize variables used to flag valid or invalid input.
	int pInputCheck = 0, qInputCheck = 0;

	printf("This program displays the truth table for right complementation.\n");

	//Print out the truth table for the function
	printf("|====================|\n");
	printf("|  p  |  q  | p RC q |\n");
	printf("|====================|\n");
	printf("|  T  |  T  |   F    |\n");
	printf("|  T  |  F  |   T    |\n");
	printf("|  F  |  T  |   F    |\n");
	printf("|  F  |  F  |   T    |\n");
	printf("|====================|\n");

	//Prompt the user for their input of p in the function
	printf("What is the value of p? Enter 1 for true or 0 for false: ");
	
	//Run a loop to verify the user input p is valid or invalid
	while ( pInputCheck == 0 )
	{
		scanf("%d", &p);

		if ( p == 0 || p == 1)
			pInputCheck = 1;
		else
			printf("Invalid input for p. Please use 1 for true or 0 for false: ");
	}

	//Prompt the user for their input of q in the function
	printf("What is the value of q? Enter 1 for true or 0 for false: ");
	
	//Run a loop to verify the user input q is valid or invalid
	while ( qInputCheck == 0 )
	{
		scanf("%d", &q);

		if ( q == 0 || q == 1)
			qInputCheck = 1;
		else
			printf("Invalid input for q. Please use 1 for true or 0 for false: ");
	}

	//Perform the calculation on the given values
	if ( q == 0 )
		result = 1;
	else if ( q == 1 )
		result = 0;

	//Return the value after the calculation
	printf("The right complement of p:%d and q:%d is %d\n", p, q, result);

	return 0;
}
