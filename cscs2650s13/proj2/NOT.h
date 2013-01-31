char NOT(arg1)
{
	char result;
	arg1 = arg1 - 48;

	if (arg1 == 1)
	{
		result = 0;
	}
	else
	{
		result = 1;
	}

	return result;
}
