/* Shawn Meas
 * Project 0 for Discrete Structures
 * Keyword given: Right Complementation
 */

#include <stdio.h>

int main()
{
	//Initialize int variables for p and q.
	int p, q, result;

	printf("This program displays the truth table for right complementation\n");

	//Print out the truth table for the function
	printf("|  p  |  q  | p RC q |\n");
	printf("|====================|\n");
	printf("|  T  |  T  |   F    |\n");
	printf("|  T  |  F  |   T    |\n");
	printf("|  F  |  T  |   F    |\n");
	printf("|  F  |  F  |   T    |\n");
	printf("|====================|\n");

	//Ask the user for their input to the function
	printf("What is the value of p? Enter 1 for true or 0 for false: ");
	scanf("%d", &p);
	printf("What is the value of q? Enter 1 for true or 0 for false: ");
	scanf("%d", &q);

	//Perform the calculation on the given values
	if ( q == 0 )
		result = 1;
	else if ( q == 1 )
		result = 0;

	//Return the value after the calculation
	
	printf("The right complement of p:%d and q:%d is %d\n", p, q, result);

	return 0;
}
