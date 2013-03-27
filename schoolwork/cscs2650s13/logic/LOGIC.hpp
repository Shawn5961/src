#define TRUESTATE '1'
#define FALSESTATE '0'
#define INVALID 'x' 

class Logic{
	char in1, in2, in3, result, sum, carry, s, r, q, qbar;
public:
	char AND(char, char);
	char OR(char, char);
	char NOT(char);
	char NAND(char, char);
	char NOR(char, char);
	char XOR(char, char);
	char HALFSUM(char, char);
	char HALFCARRY(char, char);
	char FULLSUM(char, char, char);
	char FULLCARRY(char, char, char);
};

char Logic::AND(char in1, char in2)
{
	this->in1 = in1;
	this->in2 = in2;

	if(in1 == TRUESTATE)
	{
		if (in2 == TRUESTATE)
		{
			result = TRUESTATE;
		}
		else if (in2 == FALSESTATE)
		{
			result = FALSESTATE;
		}
		else
		{
			result = INVALID;
		}
	}
	else if(in1 == FALSESTATE)
	{
		result = FALSESTATE;
	}
	else
	{
		result = INVALID;
	}

	return result;
}

char Logic::OR(char in1, char in2)
{
	this->in1 = in1;
	this->in2 = in2;

	if(in1 == TRUESTATE)
	{
		result = TRUESTATE;
	}
	else if (in1 == FALSESTATE)
	{
		if (in2 == TRUESTATE)
		{
			result = TRUESTATE;
		}
		else if (in2 == FALSESTATE)
		{
			result = FALSESTATE;
		}
		else
		{
			result = INVALID;
		}
	}
	else
	{
		result = INVALID;
	}

	return result;
}

char Logic::NOT(char in1)
{
	if(in1 == TRUESTATE)
	{
		result = FALSESTATE;
	}
	else if(in1 == FALSESTATE)
	{
		result = TRUESTATE;
	}
	else
	{
		result = INVALID;
	}

	return result;
}

char Logic::NAND(char in1, char in2)
{
	result = NOT(AND(in1, in2);

	return result;
}

char Logic::NOR(char in1, char in2)
{
	result = NOT(OR(in1, in2);

	return result;
}

char Logic::XOR(char in1, char in2)
{
	result = OR(AND(NOT(in1), in2), AND(in1, NOT(in2)));

	return result;
}

char Logic::HALFSUM(char in1, char in2)
{
	sum = XOR(in1, in2);

	return sum;
}

char Logic::HALFCARRY(char in1, char in2)
{
	carry = AND(in1, in2);

	return carry;
}

char Logic::FULLSUM(char in1, char in2, char in3)
{
	sum = XOR(XOR(in1, in2), in3);

	return sum;
}

char Logic::FULLCARRY(char in1, char in2, char in3)
{
	carry = OR(AND(XOR(in1, in2), in3), AND(in1, in2));

	return carry;
}
