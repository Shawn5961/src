#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char character[80];
	FILE *file = fopen(argv[1], "r");
	int c;
	int i = 0;


	if (argc != 2)
	{
		printf("This program requires exactly ONE command line argument to run\n");
	}
	else
	{
		character[i] = fgetc(file);
		do
		{
			if(character[i] == '\n' || character[i] == ' ')
			{	
				printf("%x\n", character[i]);
				i++;
				character[i] = fgetc(file);
			}
			else
			{
				printf("%x ", character[i]);
				i++;
				character[i] = fgetc(file);
			}
		} while(character[i] != EOF);

		fclose(file);

		return 0;
	}
}
