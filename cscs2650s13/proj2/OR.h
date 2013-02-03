char OR(input1, input2)
{
	char result;

	if (input1 == trueState)
	{
		result = trueState;
	}
	else if (input2 == trueState)
	{
		result = trueState;
	}
	else
	{
		result = falseState;
	}

	return result;
}
