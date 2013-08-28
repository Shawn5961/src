#include <stdio.h>
#include <stdarg.h>

#define FALSESTATE '0'
#define TRUESTATE '1'
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

char VAND(int numArgs, ...)
{
	va_list args;
	va_start(args, numArgs);

	char arg, result;
	int i;
	for(i = numArgs; i > 0; i--)
	{
		arg = va_arg(args, int);
		if(i == numArgs)
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

int main()
{
	printf("%c", VAND(3, '1', '1', '1'));
}
