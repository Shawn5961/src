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
	choice = getchar();
	while (getchar() != '\n');

	switch (choice)
	{
		case 'a':
		{
			printf("Input the value to be evaluated with the NOT function: ");
			arg1 = getchar();
			while (getchar() != '\n');
			printf("The NOT of %c is %d.\n", arg1, NOT(arg1));
			break;
		}
	
		case 'b':
		{
			printf("Input the first value to be evalutated with the AND function: ");
			arg1 = getchar();
			while (getchar() != '\n');
			printf("Input the second value to be evalutated with the AND function: ");
			arg2 = getchar();
			while (getchar() != '\n');
			printf("The AND of %c and %c is %d.\n", arg1, arg2, AND(arg1, arg2));
			break;
		}

		case 'c':
		{
			printf("Input the first value to be evalutated with the OR function: ");
			arg1 = getchar();
			while (getchar() != '\n');
			printf("Input the second value to be evalutated with the OR function: ");
			arg2 = getchar();
			while (getchar() != '\n');
			printf("The OR of %c and %c is %d.\n", arg1, arg2, OR(arg1, arg2));
			break;
		}

		default:
		{
			fprintf(stdout, "You have entered an invalid option.");
			break;
		}
	}
	return 0;
}
