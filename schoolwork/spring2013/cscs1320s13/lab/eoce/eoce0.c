#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 1;
	int b = 0;
	int c;
	int i;

	for(i = 1; i < 37; i++)
	{
		if((i % 4) == 0)
		{
			printf("\t%08d\n", c);
		}
		else
		{
			printf("\t%08d", c);	
		}
		c = a + b;
		a = b;
		b = c;
	}

	return 0;
}
