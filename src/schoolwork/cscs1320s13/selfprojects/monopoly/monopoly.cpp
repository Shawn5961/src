#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "property.h"

int numPlayers;
int l;
Player player[8];

void initGame()
{
	printf("Shawn Meas is a F'in Boss!");
	printf("Welcome to Meas-opoly!\n");
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

	for(l = 0; l < numPlayers; l++)
	{
		player[l].set_values(1500, 1500, l, true);
		printf("\nWhat is the name of player #%d\n", player[l].getNumber());
		player[l].setName();
		printf("\nPlayer: %s\n",player[l].getName());
		printf("Money: %d\n",player[l].getMoney());
		printf("Worth: %d\n",player[l].getWorth());
		printf("Alive: %s\n",player[l].getAlive()?"true":"false");
	}
}

int main()
{
	char actionSelect, moneyActionSelect, garbage;
	int actionSelectInt, moneyActionSelectInt, moneyChange, playerSelect, roll1, roll2, rollTotal;
	int i, j, k;
	int debugCount = 0;
	int doubleCount = 0;
	int flagDouble = 0, flagRolled = 0, flagTurnOver = 0;


	initGame();

	srand(time(NULL));

	for(i = 0; i < numPlayers; i++)
	{
		flagTurnOver = 0;
		do
		{
		printf("\n%s's turn!\n", player[i].getName());
		if(flagRolled == 0)
			printf("1: Roll\n");
		else
			printf("1: None\n");
		printf("2: Add money to current player\n");
		printf("3: Decrement money from current player\n");
		printf("4: Decrement money from current player and add to another player\n");
		printf("5: List money for current players\n");
		printf("6: List money for selected player\n");
		printf("7: List money for all players\n");
//Trade functionality goes here
		garbage = fgetc(stdin);
		actionSelect = fgetc(stdin);
		while(garbage != 10)	
		{
			garbage = fgetc(stdin);
		};
		actionSelectInt = actionSelect - 48;
//printf("\nTest %d\n", actionSelectInt);
		
		switch (actionSelectInt)
			{
			case 1:
				if(flagRolled == 0)
				{
					roll1 = rand() % 6 + 1;
					roll2 = rand() % 6 + 1;
//					roll1 = 1;
//					roll2 = 2;
					rollTotal = roll1 + roll2;
					printf("Die 1: %d\n", roll1);
					printf("Die 2: %d\n", roll2);
					printf("Total: %d\n", rollTotal);
					flagRolled = 1;

					if (roll1 == roll2)
					{
						flagDouble = 1;
					}
					else
					{
						flagDouble = 0;
						doubleCount = 0;
					}
				}
				else if(flagRolled == 1)
				{
					flagRolled = 0;
					flagTurnOver = 1;
				}
				break;

			case 2:
				printf("How much money should be added to %s\n", player[i].getName());
				garbage = fgetc(stdin);
				moneyChange = fgetc(stdin);
				moneyChange = moneyChange - 48;
				player[i].incMoney(player[i].getMoney(), moneyChange);
				break;

			case 3:
				printf("How much money should be decremented from %s\n", player[i].getName());
				garbage = fgetc(stdin);
				moneyChange = fgetc(stdin);
				moneyChange = moneyChange - 48;
				player[i].decMoney(player[i].getMoney(), moneyChange);
				break;

			case 4:
				printf("Which player should money be added to?\n");
				for(k = 0; k < numPlayers; k++)
				{
					printf("%d: %s\n", (k+1), player[k].getName());
				}
				garbage = fgetc(stdin);
				playerSelect = fgetc(stdin);
				playerSelect = playerSelect - 48;
				while(garbage != 10)	
				{
					garbage = fgetc(stdin);
				};
				printf("How much should be decremented from %s and added to %s\n", player[i].getName(), player[playerSelect - 1].getName());
				garbage = fgetc(stdin);
				moneyChange = fgetc(stdin);
				moneyChange = moneyChange - 48;
				player[i].decMoney(player[i].getMoney(), moneyChange);
				player[playerSelect - 1].incMoney(player[playerSelect - 1].getMoney(), moneyChange);
				break;

			case 5:
				printf("+----------+\n");
				printf("Player: %s\n", player[i].getName());
				printf("Money: $%d\n", player[i].getMoney());
				printf("+----------+\n");
//Worth implementation			printf("Worth: $%d\n", player[i].getWorth);
				break;
			
			case 6:
				printf("Which player's money would you like to see?\n");
				for(k = 0; k < numPlayers; k++)
				{
					printf("%d: %s\n", (k+1), player[k].getName());
				}
				garbage = fgetc(stdin);
				playerSelect = fgetc(stdin);
				playerSelect = playerSelect - 48;
				while(garbage != 10)	
				{
					garbage = fgetc(stdin);
				};
				printf("+----------+\n");
				printf("Player: %s\n", player[playerSelect - 1].getName());
				printf("Money: $%d\n", player[playerSelect - 1].getMoney());
				printf("+----------+\n");
//Worth implementation			printf("Worth: $%d\n", player[i].getWorth);
				break;

			case 7:
				printf("List of all player's money:\n");
				printf("+-------------+\n");
				for(j = 0; j < numPlayers; j++)
				{	
					printf("%s: $%d\n", player[j].getName(), player[j].getMoney());
					printf("+-------------+\n");
				}
				break;
			} 
		} while(flagTurnOver != 1);
		
//		printf("breakpoint\n");
		
//End of turn stuff.
//If doubles were rolled, decrement i so player goes again and increase double count (for three doubles rule)
		if(flagDouble == 1)
		{
			if(doubleCount < 2)
			{
				printf("You rolled doubles! Go again, bruh!\n");
				i--;
				doubleCount++;
			}
			else if(doubleCount == 2)
			{
				doubleCount = 0;
				printf("You rolled three doubles in a row. Go to jail!\n");
			}

		}
//		printf("breakpoint2\n");
//If the last player has been reached, reset player turns to the first
		
//		printf("prei = %d\n", i);
		if(i == (numPlayers - 1))
		{
			i = -1;
		}
		
//		printf("numPlayers = %d\n", numPlayers);
//		printf("i = %d\n", i);
//		printf("breakpoint3\n");
	}

}
