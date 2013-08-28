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

char NAND(char input1, char input2)
{
	char result;
	
	result = NOT(AND(input1, input2));

	return result;
}

char NOR(char input1, char input2)
{
	char result;
	
	result = NOT(OR(input1, input2));

	return result;
}

char XOR(char input1, char input2)
{
	char result;
	
	result = OR(AND(NOT(input1), input2), AND(input1, NOT(input2)));

	return result;
}

char HALFSUM(char input1, char input2)
{
	char sum;

	sum = XOR(input1, input2);

	return sum;
}

char HALFCARRY(char input1, char input2)
{
	char carry;
	
	carry = AND(input1, input2);

	return carry;
}

char FULLSUM(char input1, char input2, char input3)
{
	char sum;

	sum = XOR(XOR(input1, input2), input3);

	return sum;
}

char FULLCARRY(char input1, char input2, char input3)
{
	char carry;

	carry = OR(AND(XOR(input1, input2), input3), AND(input1, input2));

	return carry;
}

//addBinary
//stringToArray
//arrayToString
//latch

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

	printf("\n1 NOR 1: %d\n", NOR(1, 1));
	printf("1 NOR 0: %d\n", NOR(1, 0));
	printf("0 NOR 1: %d\n", NOR(0, 1));
	printf("0 NOR 0: %d\n", NOR(0, 0));

	printf("\n1 NAND 1: %d\n", NAND(1, 1));
	printf("1 NAND 0: %d\n", NAND(1, 0));
	printf("0 NAND 1: %d\n", NAND(0, 1));
	printf("0 NAND 0: %d\n", NAND(0, 0));

	printf("\n1 XOR 1: %d\n", XOR(1, 1));
	printf("1 XOR 0: %d\n", XOR(1, 0));
	printf("0 XOR 1: %d\n", XOR(0, 1));
	printf("0 XOR 0: %d\n", XOR(0, 0));

	printf("\n1 HALFSUM 1: %d\n", HALFSUM(1, 1));
	printf("1 HALFSUM 0: %d\n", HALFSUM(1, 0));
	printf("0 HALFSUM 1: %d\n", HALFSUM(0, 1));
	printf("0 HALFSUM 0: %d\n", HALFSUM(0, 0));

	printf("\n1 HALFCARRY 1: %d\n", HALFCARRY(1, 1));
	printf("1 HALFCARRY 0: %d\n", HALFCARRY(1, 0));
	printf("0 HALFCARRY 1: %d\n", HALFCARRY(0, 1));
	printf("0 HALFCARRY 0: %d\n", HALFCARRY(0, 0));

	printf("\n1 FULLSUM 1 CARRY 1: %d\n", FULLSUM(1, 1, 1));
	printf("1 FULLSUM 1 CARRY 0: %d\n", FULLSUM(1, 1, 0));
	printf("1 FULLSUM 0 CARRY 1: %d\n", FULLSUM(1, 0, 1));
	printf("1 FULLSUM 0 CARRY 0: %d\n", FULLSUM(1, 0, 0));
	printf("0 FULLSUM 1 CARRY 1: %d\n", FULLSUM(0, 1, 1));
	printf("0 FULLSUM 1 CARRY 0: %d\n", FULLSUM(0, 1, 0));
	printf("0 FULLSUM 0 CARRY 1: %d\n", FULLSUM(0, 0, 1));
	printf("0 FULLSUM 0 CARRY 0: %d\n", FULLSUM(0, 0, 0));
	
	printf("\n1 FULLCARRY 1 CARRY 1: %d\n", FULLCARRY(1, 1, 1));
	printf("1 FULLCARRY 1 CARRY 0: %d\n", FULLCARRY(1, 1, 0));
	printf("1 FULLCARRY 0 CARRY 1: %d\n", FULLCARRY(1, 0, 1));
	printf("1 FULLCARRY 0 CARRY 0: %d\n", FULLCARRY(1, 0, 0));
	printf("0 FULLCARRY 1 CARRY 1: %d\n", FULLCARRY(0, 1, 1));
	printf("0 FULLCARRY 1 CARRY 0: %d\n", FULLCARRY(0, 1, 0));
	printf("0 FULLCARRY 0 CARRY 1: %d\n", FULLCARRY(0, 0, 1));
	printf("0 FULLCARRY 0 CARRY 0: %d\n", FULLCARRY(0, 0, 0));
	
}
