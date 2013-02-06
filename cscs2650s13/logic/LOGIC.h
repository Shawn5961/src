#define TRUESTATE 1
#define FALSESTATE 0

char AND(input1, input2)
{
	char result;

	if (input1 == TRUESTATE)
	{
		if (input2 == TRUESTATE)
		{	
			result = TRUESTATE;
		}	
		else
		{
			result = FALSESTATE;
		}
	}
	else
	{
		result = FALSESTATE;
	}

	return result;
}
