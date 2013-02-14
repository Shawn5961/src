//A program written to accept a user input, and then
//attempt to guess that input.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int numPlaces, userNum, guess;
	double startTime, endTime, runTime;
	int counter;
	
	printf("What is the range of numbers you wish the program to guess\n");
	printf("1: 0 - 10\n");
	printf("2: 0 - 100\n");
	printf("3: 0 - 1000\n");
	printf("4: 0 - 10000\n");
	printf("5: 0 - 100000\n");
	scanf("%d", &numPlaces);

	printf("\nInput the number you wish the program to guess\n");
	scanf("%d", &userNum);

	printf("Break: if statement");
	
	if (userNum > (10 * numPlaces))
	{
		printf("\nThe value you chose is outside the guessable range\n");
		printf("The program will now exit\n");
		exit(0);
	}

	printf("Break: loop setup");

	counter = 0;
	startTime = time(NULL);
	srand(time(NULL));

	printf("Break: loop begins");

	do
	{
		guess = rand() * (10 * numPlaces);
		counter++;
	} while (guess != userNum);

	endTime = time(NULL);
	runTime = endTime - startTime;

	printf("It took the program %d guesses to guess the number %d", counter, userNum);
	printf("It took %d seconds to guess the number", runTime);

	return 0;
}

