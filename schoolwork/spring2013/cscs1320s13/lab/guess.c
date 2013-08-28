#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int numToGuess, numGuesses, guess;

	printf("This program generates a random number from 1 to 10, which must then be guessed\n");

	srand(time(NULL));
	numToGuess = rand() % 10 + 1;
	numGuesses = 0;

	//printf("%d\n", numToGuess);
	
	do
	{
		printf("What is your guess? (1 - 10)\n");
		scanf("%d", &guess);

		if (guess < 1 || guess > 10)
		{
			printf("I said 1-10, you fool!\n");
		}
		else if (guess == numToGuess)
		{
			printf("Congratulations! You are clearly a psychic!\n");
		}
		else if (guess != numToGuess)
		{
			printf("WRONG! Try again, bruh\n");
		}

		numGuesses++;
	} while (guess != numToGuess);

	return 0;
}