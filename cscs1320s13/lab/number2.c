#include <stdio.h>

int main()
{
	unsigned char a;
	signed char b;

	a = 0;
	b = 0;

	printf("a is: %hhu\n",a);
	printf("b is: %hhd\n",b);

	a = a-1;
	b = b-1;
	
	printf("a is: %hhu\n",a);
	printf("b is: %hhd\n",b);

	return 0;
}
