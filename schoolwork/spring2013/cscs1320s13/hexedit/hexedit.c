#include <stdio.h>
#include <stdlib.h>

char buffer[256];
int i = 0;
int lineNum = 0;
FILE *file;
fpos_t filePos;
int filePosInt;

void printBuffer()
{
//	buffer[i] = fgetc(file);
	if((buffer[i] = fgetc(file)) != EOF)
	{
		printf("     00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15\n");
		printf("%03d0 ", lineNum);
		fseek(file, -1, SEEK_CUR);
		do
		{
			buffer[i] = fgetc(file);
			if((i % 16) == 15)
			{	
				lineNum++;
				if(lineNum < 16)
				{
					printf("%02x\n%03d0 ", buffer[i], lineNum);
				}
				else
				{
					printf("%02x\n", buffer[i]);
				}
				i++;
			}
			else
			{
				printf("%02x ", buffer[i]);
				i++;
			}
		} while(buffer[i] != EOF && i < 256);
		i = 0;
		lineNum = 0;
	}
	else
	{
		printf("You have reached the end of the file\n");
	}
}

int main(int argc, char *argv[])
{
	file = fopen(argv[1], "r");
	int option;
	char charCounter;
	int numChars = 0;

//Todo: Edit value, save file, open file, new buffer, next, previous

	if (argc != 2)
	{
		printf("This program requires exactly ONE command line argument to run\n");
	}
	else
	{
/*		while(charCounter != EOF)
		{
			numChars++;
			charCounter = fgetc(file);
		};
		numChars--;
		printf("Number of characters in file: %d\n", numChars);
		
		rewind(file);

		printBuffer();
*/
		do
		{
			printf("\nEnter a command.\n");
			printf("1: Display current buffer\n");
			printf("2: Display next buffer\n");
			printf("3: Display previous buffer\n");
			printf("4: Display start of file\n");
			printf("5: Quit\n");
			scanf("%d", &option);
			
			switch (option)
			{
				case 1:
					fseek(file, -256, SEEK_CUR);
					printBuffer();
					break;
				case 2:
					printBuffer();
					break;
				case 3:
					fseek(file, -512, SEEK_CUR);
					printBuffer();
					break;
				case 4:
					rewind(file);
					printBuffer();
					break;
				case 5:
					break;
				default:
					printf("Invalid option. Please enter a valid option\n");
					break;
			}
		} while(option != 5);
	}
	fclose(file);

	return 0;
	
}
