#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *fileToOpen = argv[1];
	char buffer[256];
	FILE *fileToEdit;

	if (argc != 2)
	{
		printf("This program requires exactly ONE command line argument to run\n");
	}
	else
	{
		fileToEdit = fopen(fileToOpen, "r");

		printf("fileToOpen = %s\n", fileToOpen);
		
		while(fgets(buffer,256, fileToEdit) != NULL)
			printf("%s", buffer);

		fclose(fileToEdit);

		return 0;
	}
}
