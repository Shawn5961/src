#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, *b;
	short int c;
	char d;
	float e;

	b = (int *) malloc (sizeof(int) * 1);

	fprintf(stdout, "Enter an integer: ");
	fscanf(stdin, "%u", &a);

	fprintf(stdout, "Enter another integer: ");
	fscanf(stdin, "%u", b);

	fprintf(stdout, "Enter a short int: ");
	fscanf(stdin, "%hu", &c);

	fprintf(stdout, "Enter a float value: ");
	fscanf(stdin, "%f", &e);
	
	fprintf(stdout, "Enter a char: ");
	getchar();
	fscanf(stdin, "%c", &d);


	fprintf(stdout, "Your ints are: %u and %u\n",a, *b);
	fprintf(stdout, "Your short int is: %hu\n", c);
	fprintf(stdout, "Your float (trimmed at 2 decimal places) is: %.2f\n", e);
	fprintf(stdout, "Your char is: '%c'\n", d);

	return 0;
}
