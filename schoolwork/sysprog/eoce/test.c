#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *inFile;

	inFile = fopen(argv[1], "r");
	int num = 0;
	int i = 0;
	int numArgs = 0;

	fscanf(inFile, "%d", &num);
	while(!feof(inFile))
	{
		fscanf(inFile, "%d", &num);
		numArgs++;
	}
	
	printf("%d\n", numArgs);
	
	int number[numArgs];
	rewind(inFile);

	fscanf(inFile, "%d", &num);
	for(i = 0; i < numArgs; i++)
	{
		number[i] = num;
		fscanf(inFile, "%d", &num);
	}

	for(i = 0; i < numArgs; i++)
	{
		printf("%d\n", number[i]);
	}

	fclose(inFile);

	return 0;
}
