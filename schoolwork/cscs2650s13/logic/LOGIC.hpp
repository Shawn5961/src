#define TRUESTATE '1'
#define FALSESTATE '0'
#define INVALID 'x' 

class Logic{
	char in1, in2, result;
public:
	char AND(char, char);
	char OR(char, char);
	char NOT(char);
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
