#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, *b;

	a = 12;
	b = &a;

	fprintf(stdout, "[a] address is: 0x%X\n", &a);
	fprintf(stdout, "[a] contains: %d\n", a);
//	fprintf(stdout, "[a] dereferences to: %d\n", a);
	fprintf(stdout, "[b] address is: 0x%X\n", &b);
	fprintf(stdout, "[b] contains: 0x%X\n", b);
	fprintf(stdout, "[b] dereferences to: %d\n", *b);

	return 0;
}	
