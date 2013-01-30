#include <stdio.h>

int main()
{
	unsigned char a = 0;
	fprintf(stdout, "Before:\n-------\n");
	fprintf(stdout, "a address: 0x%X\n", &a);
	fprintf(stdout, "a contains: %hhu\n", a);

	a = a-1;

	fprintf(stdout, "After:\n-------\n");
	fprintf(stdout, "a address: 0x%X\n", &a);
	fprintf(stdout, "a contains: %hhu\n", a);
	fprintf(stdout, "The size of an unsigned char is %hhu bytes\n", sizeof(a));

	return(0);
}
