#define TRUESTATE '1'
#define FALSESTATE '0'
#define INVALID 'x' 

char AND(input1, input2)
{
	char result;
	
	if (input1 == TRUESTATE)
	{
		if (input2 == TRUESTATE)
		{	
			result = TRUESTATE;
		}	
		else if (input2 == FALSESTATE)
		{
			result = FALSESTATE;
		}
		else
		{
			result = INVALID;
		}
	}
	else if (input1 == FALSESTATE)
	{
		result = FALSESTATE;
	}
	else
	{
		result = INVALID;
	}

	return result;
}

char OR(input1, input2)
{
	char result;
	
	if (input1 == TRUESTATE)
	{
		result = TRUESTATE;
	}
	else if (input1 == FALSESTATE)
	{
		if (input2 == TRUESTATE)
		{
			result = TRUESTATE;
		}
		else if (input2 == FALSESTATE)
		{
			result = FALSESTATE;
		}
	}
	else
	{
		result = INVALID;
	}

	return result;
}

char NOT(input1)
{
	char result;
	
	if (input1 == TRUESTATE)
	{
		result = FALSESTATE;
	}
	else if (input1 == FALSESTATE)
	{
		result = TRUESTATE;
	}
	else
	{
		result = INVALID;
	}

	return result;
}

char NAND(input1, input2)
{
	char result;
	
	result = NOT(AND(input1, input2));

	return result;
}

char XOR(input1, input2)
{
	char result;
	
	result = OR(AND(NOT(input1), input2), AND(input1), (NOT(input2)));

	return result;
}

char HALFSUM(input1, input2)
{
	char sum;

	sum = XOR(input1, input2);

	return sum;
}

char HALFCARRY(input1, input2)
{
	char carry;
	
	carry = AND(input1, input2);

	return carry;
}

char FULLSUM(input1, input2, input3)
{
	char sum;

	sum = XOR(XOR(input1, input2), input3);

	return sum;
}

char FULLCARRY(input1, input2, input3)
{
	char carry;

	carry = OR(AND(XOR(input1, input2), input3), AND(input1, input2);

	return carry;
}
