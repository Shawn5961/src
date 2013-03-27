#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string.h>

//#define 1 "Rock"
//#define 2 "Paper"
//#define 3 "Scissors"



int main()
{
	char cpuMove;
	float cpuMoveCheck, winLoseRatio;
	int userMove, numWon, numLost, playAgain;

	numWon = 0;
	numLost = 0;

	printf("This is a simple game of Rock, Paper, Scissors\n");

	do
	{
		printf("\nPick a move\n");
		printf("1: Rock\n");
		printf("2: Paper\n");
		printf("3: Scissors\n");
		scanf("%d", &userMove);
		getchar();

		srand(time(NULL));
		cpuMoveCheck = rand() % 10;

		if (cpuMoveCheck > 0 && cpuMoveCheck <= 3.3)
		{
			cpuMove = 1;
		}
		else if (cpuMoveCheck > 3.3 && cpuMoveCheck <= 6.6)
		{
			cpuMove = 2;
		}
		else if (cpuMoveCheck > 6.6 && cpuMoveCheck <= 10)
		{
			cpuMove = 3;
		}

		printf("%f", cpuMoveCheck);
		printf("\nYou chose %d and your opponent chose %d\n", userMove, cpuMove);

		if (userMove == cpuMove)
		{
			printf("DRAW!\n");
		}
		else if (userMove > cpuMove || (userMove == 1 && cpuMove == 3))
		{
			printf("YOU WIN!\n");
			numWon++;
		}
		else
		{
			printf("YOU LOSE!\n");
			numLost++;
		}

		printf("\nWould you like to play again?\n");
		printf("1: Yes\n");
		printf("2: No\n");
		scanf("%d", &playAgain);
		getchar();

	} while (playAgain == 1);

	if (numLost == 0)
	{
		winLoseRatio = 1;
	}
	else
	{
		winLoseRatio = (numWon / numLost);
	}
	

	printf("\nThank you for playing!\n");
	printf("Won: %d\tLost: %d\n", numWon, numLost);
	printf("Win to Loss Ratio: %.3f", winLoseRatio);

	return 0;
}