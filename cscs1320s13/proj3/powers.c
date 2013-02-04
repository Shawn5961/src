#include <stdio.h>

int main(int argc, char *argv[])
{
	int base, newbase, power, result;
	int i, j, k;

	base = atoi(argv[1]);
	power = atoi(argv[2]);
	result = base;
	newbase = base;

	printf("%d %d\n",base,power);

	for ( j = 1; j < power; j++)
	{
		//printf("Loop 1: %d\n",result);

		for (i = 1; i < base; i++)
		{
			//printf("Loop 2: %d\n",result);

			for (k = 0; k < newbase; k++)
			{
				result++;
				//printf("Loop 3: %d\n",result);
			}	
		}
	newbase = result;
	}

	printf("The number %d raised to the power %d is %d\n",base,power,result);

	return 0;

}
