#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char buffer[256];
	FILE *file = fopen(argv[1], "r");
	int option;
	int i = 0;
	int lineNum = 0;

//Todo: Edit value, save file, open file, new buffer, next, previous

	if (argc != 2)
	{
		printf("This program requires exactly ONE command line argument to run\n");
	}
	else
	{
		do
		{
			printf("\nEnter a command.\n");
			printf("1: Display next buffer\n");
			printf("2: Quit\n");
			scanf("%d", &option);
			
			switch (option)
			{
				case 1:
					buffer[i] = fgetc(file);
					if(buffer[1] != EOF)
					{
						printf("     00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15\n");
						printf("%03d0 ", lineNum);
						do
						{
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
								buffer[i] = fgetc(file);
							}
							else
							{
								printf("%02x ", buffer[i]);
								i++;
								buffer[i] = fgetc(file);
							}
						} while(buffer[i] != EOF && i < 256);
						i = 0;
						lineNum = 0;
					}
					else
					{
						printf("You have reached the end of the file\n");
						printf("Please run the program again\n");
						option = 2;
					}
					break;
				case 2:
					break;
				default:
					printf("Invalid option. Please enter a valid option\n");
					break;
			}
		} while(option != 2);
	}
	fclose(file);

	return 0;
	
}
