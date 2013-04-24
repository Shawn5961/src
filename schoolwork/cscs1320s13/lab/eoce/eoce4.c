#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *name1;
	char name2[32];
	char *name3 = (char *) malloc (sizeof(char)*32);
	name1 = name2;
	sprintf(name1, "Mr. Balloon Hands");
	sprintf(name3, "John Jacob Jingleheimer Schmidt");

	printf("%lu\n", sizeof(char*));
	printf("%lu\n", sizeof *name3);
	printf("%c\n", name1[10]);
	printf("%c\n", name3[8]);
}
