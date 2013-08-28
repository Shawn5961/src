/*
	2:  * EoCEsrc.c - sample code for use with EoCE
	3:  *
	4:  * To compile: gcc -o eoceprog EoCEsrc.c -lpthread
	5:  * To execute: ./eoceprog 55 44 33 22 11 12 23 34 45 5 1 3 4 2
	6:  *
	7:  */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

struct localinfo {
	unsigned char value;
};

FILE *fPtr;
FILE *inFile;
FILE *sortFile;

int main(int argc, char **argv)
{
	void *process(void *);
	unsigned char i = 0;
	struct localinfo local;
	
	if (argc < 2)
	{
		printf("Please provide a filename to read numbers from\n");
		exit(1);
	}

	//Open the file specified by the command line argument
	inFile = fopen(argv[1], "r");

	//Set required variables for counting number of args, setting args
	int num, numArgs = 0;
	int k;

	//Count number of integers in file
	fscanf(inFile, "%d", &num);
	while(!feof(inFile))
	{
		fscanf(inFile, "%d", &num);
		numArgs++;
	}

	//Create an int array the size of number of ints in file
	int number[numArgs];

	//Set file pointer back to start
	rewind(inFile);

	//Read integers from file
	fscanf(inFile, "%d", &num);
	for(k = 0; k < numArgs; k++)
	{
		number[k] = num;
		fscanf(inFile, "%d", &num);
	}
	
	fclose(inFile);

	pthread_t threads[numArgs];

	fPtr = fopen("datafile", "w");
	if(fPtr == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}

	for(i = 0; i < numArgs; i++)
	{
		local.value = number[i];
		pthread_create(&threads[i], NULL, (void *) process, (void *) &local);
		usleep(32);
	}

	for(i = 0; i < numArgs; i++)
		pthread_join(threads[i], NULL);

	fprintf(fPtr, "\n");
	fclose(fPtr);

	sortFile = fopen("datafile", "r");
	
	numArgs = 0;
	
	//Count number of integers in file
	fscanf(sortFile, "%d", &num);
	while(!feof(sortFile))
	{
		fscanf(sortFile, "%d", &num);
		numArgs++;
	}

	//Create an int array the size of number of ints in file
	int reverseSort[numArgs];

	//Set file pointer back to start
	rewind(sortFile);

	//Read integers from file

	//Read integers from sorted file
	fscanf(sortFile, "%d", &num);
	for(k = 0; k < numArgs; k++)
	{
		reverseSort[k] = num;
		fscanf(sortFile, "%d", &num);
	}

	for(k = (numArgs - 1); k >= 0; k--)
		printf("%d ", reverseSort[k]);

	printf("\n");

	fclose(sortFile);

	return(0);
}

void *process(void *foreign)
{
	struct localinfo *thing = foreign;
	int data = thing -> value;
	sleep((int)(data & 0xFF));
	fprintf(fPtr, "%d ", data);
	fflush(stdout);
}
