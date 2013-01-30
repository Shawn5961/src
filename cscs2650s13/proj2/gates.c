#include <stdio.h>
#include "NOT.h"
#include "OR.h"
#include "AND.h"

int main()
{
	char arg1, arg2, choice;

	printf("Please choose an operation:\n");
	printf("a) NOT\n");
	printf("b) AND\n");
	printf("c) OR\n");
	scanf("%c", &choice);

	switch (choice)
	{
		case 'a':
		{
			printf("Input the value to be evaluated with the NOT function: ");
			scanf("%c", &arg1);
			printf("The NOT of %c is %c.\n", arg1, NOT(arg1));
			break;
		}
	
		case 'b':
		{
			printf("Input the first value to be evalutated with the AND function: ");
			scanf("%c", &arg1);
			printf("Input the second value to be evalutated with the AND function: ");
			scanf("%c", &arg2);
			printf("The AND of %c and %c is %c.\n", arg1, arg2, AND(arg1, arg2));
			break;
		}

		case 'c':
		{
			printf("Input the first value to be evalutated with the OR function: ");
			scanf("%c", &arg1);
			printf("Input the second value to be evalutated with the OR function: ");
			scanf("%c", &arg2);
			printf("The OR of %c and %c is %c.\n", arg1, arg2, OR(arg1, arg2));
			break;
		}

		default:
		{
			fprintf(stdout, "You have entered an invalid option.");
		}
	}
	return 0;
}
