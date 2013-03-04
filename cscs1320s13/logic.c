#include <stdio.h>

char NOT(char input1)
{
	char result;
	
	if (input1 == 1)
	{
		result = 0;
	}
	else if (input1 == 0)
	{
		result = 1;
	}

	return result;
}



char AND(char input1, char input2)
{
	char result;
	
	if (input1 == 1)
	{
		if (input2 == 1)
		{	
			result = 1;
		}	
		else if (input2 == 0)
		{
			result = 0;
		}
	}
	else if (input1 == 0)
	{
		result = 0;
	}

	return result;
}



char OR(char input1, char input2)
{
	char result;
	
	if (input1 == 1)
	{
		result = 1;
	}
	else if (input1 == 0)
	{
		if (input2 == 1)
		{
			result = 1;
		}
		else if (input2 == 0)
		{
			result = 0;
		}
	}

	return result;
}



int main()
{
	printf("\nNOT 1: %d\n", NOT(1));
	printf("NOT 0: %d\n", NOT(0));

	printf("\n1 AND 1: %d\n", AND(1, 1));
	printf("1 AND 0: %d\n", AND(1, 0));
	printf("0 AND 1: %d\n", AND(0, 1));
	printf("0 AND 0: %d\n", AND(0, 0));

	printf("\n1 OR 1: %d\n", OR(1, 1));
	printf("1 OR 0: %d\n", OR(1, 0));
	printf("0 OR 1: %d\n", OR(0, 1));
	printf("0 OR 0: %d\n", OR(0, 0));
}