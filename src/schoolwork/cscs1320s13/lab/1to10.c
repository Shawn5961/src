#include <stdio.h>

int main()
{
	int i;

	for(i = 12; i >= 0; i--)
	{
		if(i == 10)
		{
			printf("Frakkin' %d\n", i);
		}
		else if (i == 6)
		{
			printf("Nobody likes a six\n");
		}
		else
		{	
			printf("%d\n", i);
		}
	}

	return 0;
}