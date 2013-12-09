/*	Author:	Shawn Meas
 *	Date:	12/06/13
 *	Purpose:Test function for my set class. Creates a set object of size 100
 *	and performs various operations on the set object.
 */

#include "set.h"
#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int option, input;

	printf("This program is for set operation. It works with sets up to size 100\n");
	printf("Please build your set.\n");
	Set mySet;

	do
	{
		printf("Please select an option.\n");
		printf("1: Display set\n");
		printf("2: Display set permuations\n");
		printf("3: Display super set\n");
		printf("4: Display power set\n");
		printf("5: Sort set\n");
		printf("6: Search set\n");
		printf("7: Mod set\n");
		printf("0: Exit\n");
		scanf("%d", &option);

		switch( option )
		{
			case 1:
				mySet.printSet();
				break;

			case 2:
				mySet.printSetPerm(mySet.getSize());
				break;

			case 3:
				mySet.printSuperSet();
				break;

			case 4:
				mySet.printPowerSet();
				break;

			case 5:
				printf("1: Ascending Sort\n");
				printf("2: Descending Sort\n");
				scanf("%d", &input);
				if( input == 1 )
					mySet.printSortedSet();
				else if( input == 2)
					mySet.printReverseSortedSet();
				break;

			case 6:
				printf("Enter a value to search for:\n");
				scanf("%d", &input);
				if( mySet.searchSet(input) == true )
					printf("Value exists in set.\n");
				else
					printf("Value does not exist in set.\n");
				break;

			case 7:
				printf("Performing modulus on set.\n");
				printf("Enter a modulus value (-1 for default modulus based on set size)\n");
				scanf("%d", &input);
				if( input > 0 )
					printf("Result of modulus %d on set: %d\n", input, mySet.modSet(input));
				else
					printf("Result of modulus %d on set: %d\n", mySet.getSize(), mySet.modSet());
				break;

			case 0:
				break;

			default:
				printf("Invalid option. Please re-enter.\n");
				break;
		}
	} while( option != 0 );

	return 0;

}
