#define TRUESTATE '1'
#define FALSESTATE '0'
#define INVALID 'x' 

char AND(char input1, char input2)
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

char OR(char input1, char input2)
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

char NOT(char input1)
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

char MULTIPLEX(char input1, char x0, char x1)
{
	char result;

	result = OR(AND(NOT(NOT(input1)), x1), AND(NOT(input1), x0));

	return result;
}

char DEMUX(char inputA, char in)
{
	struct demuxOut; 
	{
		char out0;
		char out1;
	};

	out0 = AND(NOT(inputA), IN);
	out1 = AND(NOT(NOT(inputA), IN);

	return demuxOut;
}

char VAND(int numArgs, ...)
{
	va_list args;
	va_start(args, numArgs);
	
	char arg, result;
	int i;

	for (i = 0; i < numArgs; i++)
	{
		if (i == numArgs)
		{
			result = arg;
		}
		else
		{
			result = AND(result, arg);
		}
	}

	va_end(args);

	return result;
}

char NANDL(char input1, char input2)
{
	struct nandlOut
	{
		char out1, out2;
	};

	out1 = NAND(input1, out2);
	out2 = NAND(input2, out1);

	return nandlOut;	
} 

char NORL(char input1, char input2)
{
	struct norlOut
	{
		char out1, out2;
	};

	out1 = NOR(input1, out2);
	out2 = NOR(input2, out1);

	return norlOut;	
} 

char CLOCKNAND(char input1, char input2, char clock)
{
	struct clockNandOut{
		char out1, out2;
	};

	out1 = NAND(NAND(input1, clock), out2);
	out2 = NAND(NAND(input1, clock), out1);

	return clockNandOut;
}

char RSFLIPFLOP(char input1, char input2, char clock)
{
	struct rsFlipFlopOut{
		char out1, out2;
	};

	out1 = NAND(NAND(,NOT(clock)),out2)
	out2 = NAND(NAND(,NOT(clock)),out1)

	return rsFlipFlopOut;	
}