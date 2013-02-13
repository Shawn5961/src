#include <stdio.h>
#include <stdlib.h>
#include "LOGIC.h"

int main(int argc, char* argv[])
{
	char input1, input2, carry, choice, result;
	
	printf("Choose your desired operation\n");
	printf("1: NOT\n");
	printf("2: AND\n");
	printf("3: OR\n");
	printf("4: XOR\n");
	printf("5: HALFSUM\n");
	printf("6: HALFCARRY\n");
	printf("7: FULLSUM\n");
	printf("8: FULLCARRY\n");
	printf("9: EXIT\n");
	choice = getchar();
	getchar();

	printf("\nThis program is set to work with the following states:\n");
	printf("TRUE:	%c\n", TRUESTATE);
	printf("FALSE:	%c\n", FALSESTATE); 

	if (choice == '1')
	{
		printf("\nWhat is the input state to be operated on?\n");
		input1 = getchar();
		getchar();
	}
	else if (choice == '7' || choice == '8')
	{
		printf("\nWhat is the first input state to be operated on?\n");
		input1 = getchar();
		getchar();
		printf("What is the second input state to be operated on?\n");
		input2 = getchar();	
		getchar();
		printf("What is the carry state to be operated on?\n");
		carry = getchar();
		getchar();
	}
	else if (choice != '9' && choice != '8')
	{
		printf("\nWhat is the first input state to be operated on?\n");
		input1 = getchar();
		getchar();
		printf("What is the second input state to be operated on?\n");
		input2 = getchar();
		getchar();	
	}
	else
	{
		printf("\nThank you for using the program\n");
		exit(0);
	}

	switch(choice)
	{
		case '1':
			result = NOT(input1);
			printf("NOT %c = %c\n", input1, result);
			break;
			
		case '2':
			result = AND(input1, input2);
			printf("%c AND %c = %c\n", input1, input2, result);
			break;
			
		case '3':
			result = OR(input1, input2);
			printf("%c OR %c = %c\n", input1, input2, result);
			break;
			
		case '4':
			result = XOR(input1, input2);
			printf("%c XOR %c = %c\n", input1, input2, result);
			break;
			
		case '5':
			result = HALFSUM(input1, input2);
			printf("%c HALFSUM %c = %c\n", input1, input2, result);
			break;
			
		case '6':
			result = HALFCARRY(input1, input2);
			printf("%c AND %c = %c\n", input1, input2, result);
			break;

		case '7':
			result = FULLSUM(input1, input2, carry);
			printf("%c FULLSUM %c CIN %c = %c\n",input1, input2, carry, result);
			break;
			
		case '8':
			result = FULLCARRY(input1, input2, carry);
			printf("%c FULLCARRY %c CIN %c = %c\n",input1, input2, carry, result);
			break;
	}

	return 0;
}
