char AND(input1, input2)
{
	char result;

	if (input1 == trueState)
	{
		if (input2 == trueState)
		{
			result = trueState;
		}
		else
		{
			result = falseState;
		}
	}
	else
	{
		result = falseState;
	}

	return result;
}
