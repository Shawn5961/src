//A program written to accept a user input, and then
//attempt to guess that input.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	int numPlaces, userNum, guess, guessMax;
	int counter;
	
	printf("What is the range of numbers you wish the program to guess\n");
	printf("1: 0 - 10\n");
	printf("2: 0 - 100\n");
	printf("3: 0 - 1000\n");
	printf("4: 0 - 10000\n");
	printf("5: 0 - 100000\n");
	scanf("%d", &numPlaces);
	getchar();

	printf("\nInput the number you wish the program to guess\n");
	scanf("%d", &userNum);
	getchar();

//printf("\nBreak: if statement\n");
	
	if (userNum > (10 * numPlaces))
	{
		printf("\nThe value you chose is outside the guessable range\n");
		printf("The program will now exit\n");
		exit(0);
	}

//printf("\nBreak: loop setup\n");

	counter = 0;
	guessMax = pow(10, numPlaces);
	srand(time(NULL));

//printf("\nBreak: loop begins\n");

	do
	{
		guess = rand() % guessMax;
		printf("%d\n", guess);
		counter++;
	} while (guess != userNum);


	printf("\nIt took the program %d guesses to guess the number %d\n", counter, userNum);

	return 0;
}

