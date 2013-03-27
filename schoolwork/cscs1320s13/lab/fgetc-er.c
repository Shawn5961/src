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

	if (a >= 48 && a < 57)
	{	
		a = a - 48;
	}
	if (b >= 48 && b < 57)
	{	
		b = b - 48;
	}
	if (c  >= 48 && c < 57)
	{	
		c = c - 48;
	}
	if (d >= 48 && d < 57)
	{	
		d = d - 48;
	}
	
	fprintf(stdout, "Your entered numbers are %hhu, %hhu, %hhu, and %hhu\n", a, b, c, d);

	return 0;
}
