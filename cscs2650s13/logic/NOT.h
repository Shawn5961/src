char NOT(input)
{
	char result;

	if (input == trueState)
	{
		result = falseState;
	}
	else
	{
		result = trueState;
	}

	return result;
}
