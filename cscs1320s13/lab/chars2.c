#include <stdio.h>
 
int main()
{
	char a, b, c;
		 
	a = 0x41;
	b = 97;
	c = '1';
					 
	printf("a is %hhu but can be mapped to '%c' in ASCII\n", a, a);
	printf("b is %hhu but can be mapped to '%c' in ASCII\n", b, b);
	printf("c is %hhu but can be mapped to '%c' in ASCII\n", c, c);
								 
	a = a + 1;
	b = b - ' ';
	c = c * 2;   // this is a *, we are multiplying
	
	printf("After calculation values\n");
	printf("a is %hhu but can be mapped to '%c' in ASCII\n", a, a);
	printf("b is %hhu but can be mapped to '%c' in ASCII\n", b, b);
	printf("c is %hhu but can be mapped to '%c' in ASCII\n", c, c);

	return(0);
}
