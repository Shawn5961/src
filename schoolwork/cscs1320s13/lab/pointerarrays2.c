#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *initials, i = 0;
	

	initials = (char *) malloc (sizeof(char) * 4);

	fprintf(stdout, "Enter a 3 character set of initials and hit ENTER: ");
	*(initials+i) = fgetc(stdin);
	i++;

	*(initials+i) = fgetc(stdin);
	i++;

	*(initials+i) = fgetc(stdin);
	i++;

	*(initials+i) = fgetc(stdin);

	fprintf(stdout, "You entered %s\n", initials);

	return 0;
}
