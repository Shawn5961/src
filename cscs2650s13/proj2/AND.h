char AND(arg1, arg2)
{
	char result;
	arg1 = arg1 - 48;
	arg2 = arg2 - 48;

	if (arg1 == 1)
	{
		if (arg2 == 1)
		{
			result = 1;
		}
		else
		{
			result = 0;
		}
	}
	else
	{
		result = 0;
	}

	return result;
}
