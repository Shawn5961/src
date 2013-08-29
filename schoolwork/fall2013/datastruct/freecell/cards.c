#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int cardVal[52];
char cardSuit[52];

struct shuffledDeck{
	int value[52];
	char suit[52];
};

struct shuffledDeck deck;

int deckInit()
{
	int cardNum;
	char suit;

	int i, j, k = 0;

	for ( i = 0; i < 4; i++ )
	{
		switch (i)
		{
			case 0:
				suit = 'c';
				break;

			case 1:
				suit = 'd';
				break;

			case 2:
				suit = 'h';
				break;

			case 3:
				suit = 's';
				break;
		}
		
		for ( j = 1; j <= 13; j++ )
		{
			cardVal[k] = j;
			cardSuit[k] = suit;
			k++;
		}
	}

/*	for ( k = 0; k < 52; k++ )
	{
		printf("Card %d: %d%c\n", k+1, cardVal[k], cardSuit[k]);
	}
*/

	return 0;
}

int deckShuffle()
{
	deckInit();

	int cardPick;
	int cardFlag[52];

	int i, j;

	for ( i = 0; i < 52; i++ )
	{
		cardFlag[i] = 0;
	}

	for ( j = 0; j < 52; j++ )
	{
		cardPick = rand() % 52;

		if ( cardFlag[cardPick] == 0 )
		{
			deck.value[j] = cardVal[cardPick];
			deck.suit[j] = cardSuit[cardPick];
			cardFlag[cardPick] = 1;
		}
		else
		{
			j--;
		}
	}

	return 0;
}

int main()
{
	srand(time(NULL));
	int i;

	deckShuffle();

	for ( i = 0; i < 52; i++ )
	{
		printf("Card %d: %d%c\n", i+1, deck.value[i], deck.suit[i]);
	}

	return 0;
}
