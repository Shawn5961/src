#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"

int main()
{
	int numPlayers;
	int i;
	Player player[8];

	printf("Welcome to the Meas Monopoly Helper.\n");
	printf("This program was written to keep track of player's current money, networth, and to roll for turns.\n");
	printf("\nTo get started, how many people will be playing?\n");
	
	do 
	{
		scanf("%d", &numPlayers);
		getchar();

		if (numPlayers > 8)
		{
			printf("Monopoly can only be played with 2-8 players, you fool!\n");
			printf("Lets try that again. How many people will be playing?\n");
		}
		else if (numPlayers == 1)
		{
			printf("You can't play Monopoly alone. Go make some friends!\n");
			printf("Lets try that again. How many people will be playing?\n");
		}
	}
	while (numPlayers < 2 || numPlayers > 8);

	for(i = 0; i < numPlayers; i++)
	{
		player[i].set_values(1500, 1500, i, true);
		printf("\nPlayer: %d\n",player[i].getNumber());
		printf("Money: %d\n",player[i].getMoney());
		printf("Worth: %d\n",player[i].getWorth());
		printf("Alive: %s\n",player[i].getAlive()?"true":"false");
	}

	do
	{
		

		if(numPlayers == 1)


	} while (numPlayers > 1);

	printf("Congratulations player %d!!! You won!");

}