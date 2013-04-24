#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *name1, n;
	char name2[32];
	char *name3 = (char *) malloc (sizeof(char)*32);
	name1 = name2;
	sprintf(name3, "John Jacob Jingleheimer Schmidt");

	printf("%p\n", name1);
	printf("%p\n", name2);
	printf("%p\n", name3);
}
