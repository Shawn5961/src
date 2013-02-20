#include <stdio.h>

int main()
{
	char a, b, c, d;

	fprintf(stdout, "Enter a char: ");
	a = fgetc(stdin);
	
	fprintf(stdout, "Enter a char: ");
	getchar();
	b = fgetc(stdin);
	
	fprintf(stdout, "Enter a char: ");
	getchar();
	c = fgetc(stdin);
	
	fprintf(stdout, "Enter a char: ");
	getchar();
	d = fgetc(stdin);

	fprintf(stdout, "Your entered ASCII chars %hhu, %hhu, %hhu, and %hhu\n", a, b, c, d);

	return 0;
}
