#include <stdio.h>
#include <time.h>
#include <math.h>
#include "stack.h"

int main()
{
	srand(time(NULL));

	int cardNum, shufflePick;
	int tempCardArray[104], shuffleCardArray[104];
	int shuffleFlag[104];
	char suit;
	char tempSuitArray[104], shuffleSuitArray[104];

	int i, j, k = 0;

	int moveArray[4], inProgress = 1, foundationComplete[8], numberComplete = 0;
	int option, option2, option3;
	int input1, input2;

	Stack *deck = new Stack(104);

	Node *tmp, *tmp2;

	for( i = 0; i < 8; i++ )
	{
		j = i % 4;
		switch( j )
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

		for( cardNum = 1; cardNum <= 13; cardNum++ )
		{
			tempCardArray[k] = cardNum;
			tempSuitArray[k] = suit;
			k++;
		}
	}

	for( i = 0; i < 104; i++ )
		shuffleFlag[i] = 0;

	for( i = 0; i < 104; i++ )
	{
		shufflePick = rand() % 104;

		if( shuffleFlag[shufflePick] == 0 )
		{
//			shuffleCardArray[i] = tempCardArray[i];
//			shuffleSuitArray[i] = tempSuitArray[i];
//			shuffleFlag[i] = 1;
			shuffleCardArray[i] = tempCardArray[shufflePick];
			shuffleSuitArray[i] = tempSuitArray[shufflePick];
			shuffleFlag[shufflePick] = 1;
		}
		else
			i--;
	}

	for( i = 0; i < 104; i++ )
	{
		tmp = new Node(shuffleCardArray[i], shuffleSuitArray[i]);
		deck->push(tmp);
	}

	for( i = 0; i < 8; i++ )
		foundationComplete[i] = 0;

	Stack *tableau[10];
	Stack *foundation[8];
	Stack *displayStack = new Stack(17);
	Stack *waste = new Stack(64);

	for( i = 0; i < 10; i++ )
	{
		tableau[i] = new Stack(17);
		for( j = 0; j < 4; j++ )
		{
			tmp = deck->pop();
			tableau[i]->push(tmp);
		}
	}

	for( i = 0; i < 8; i++ )
		foundation[i] = new Stack(13);

	tmp = deck->pop();
	waste->push(tmp);


	do
	{
		for( i = 0; i < 4; i++ )
			moveArray[i] = 0;

		for( i = 0; i < 8; i++ )
		{
			printf("Foundation %d: ", i);
			tmp = foundation[i]->pop();
			while( tmp != NULL )
			{
				displayStack->push(tmp);
				tmp = foundation[i]->pop();
			}

			tmp = displayStack->pop();
			while( tmp != NULL )
			{
				if( tmp->getValue() >= 2 && tmp->getValue() < 10 )
					printf(" %d%c ", tmp->getValue(), tmp->getSuit());
				else if( tmp->getValue() == 1 )
					printf(" A%c ", tmp->getSuit());
				else if( tmp->getValue() == 10 )
					printf("10%c ", tmp->getSuit());
				else if( tmp->getValue() == 11 )
					printf(" J%c ", tmp->getSuit());
				else if( tmp->getValue() == 12 )
					printf(" Q%c ", tmp->getSuit());
				else if( tmp->getValue() == 13 )
					printf(" K%c ", tmp->getSuit());
				foundation[i]->push(tmp);
				tmp = displayStack->pop();
			}
			printf("\n");
		}

		printf("\n");

		for( i = 0; i < 10; i++ )
		{
			printf("   Tableau %d: ", i);
			tmp = tableau[i]->pop();
			while( tmp != NULL )
			{
				displayStack->push(tmp);
				tmp = tableau[i]->pop();
			}

			tmp = displayStack->pop();
			while( tmp != NULL )
			{
				if( tmp->getValue() >= 2 && tmp->getValue() < 10 )
					printf(" %d%c ", tmp->getValue(), tmp->getSuit());
				else if( tmp->getValue() == 1 )
					printf(" A%c ", tmp->getSuit());
				else if( tmp->getValue() == 10 )
					printf("10%c ", tmp->getSuit());
				else if( tmp->getValue() == 11 )
					printf(" J%c ", tmp->getSuit());
				else if( tmp->getValue() == 12 )
					printf(" Q%c ", tmp->getSuit());
				else if( tmp->getValue() == 13 )
					printf(" K%c ", tmp->getSuit());
				tableau[i]->push(tmp);
				tmp = displayStack->pop();
			}
			printf("\n");

			/*tmp = tempStack->pop();
			while( tmp != NULL )
			{
				tableau[i]->push(tmp);
				tmp = tempStack->pop();
			}*/
		}

		printf("\nCards in deck: %d", deck->getListSize());
		if( waste->getListSize() > 0 )
		{
			tmp = waste->pop();
			printf("\tWaste: ");
			if( tmp->getValue() >= 2 && tmp->getValue() < 10 )
				printf("%d%c ", tmp->getValue(), tmp->getSuit());
			else if( tmp->getValue() == 1 )
				printf("A%c ", tmp->getSuit());
			else if( tmp->getValue() == 10 )
				printf("10%c ", tmp->getSuit());
			else if( tmp->getValue() == 11 )
				printf("J%c ", tmp->getSuit());
			else if( tmp->getValue() == 12 )
				printf("Q%c ", tmp->getSuit());
			else if( tmp->getValue() == 13 )
				printf("K%c ", tmp->getSuit());
			printf("\n");
			waste->push(tmp);
		}
		else
			printf("\tWaste: empty\n");

		printf("Please choose an option\n");
		printf("1: Display\n");
		printf("2: Draw card\n");
		printf("3: Move card\n");
		printf("0: Quit\n");
		scanf("%d", &option);

		switch( option )
		{
			case 1:
				break;

			case 2:
				if( deck->getListSize() > 0 )
				{
					tmp = deck->pop();
					waste->push(tmp);
				}
				else
					printf("No cards remain in deck.\n");
				break;

			case 3:
				printf("Move card from where?\n");
				printf("1: Tableau\n");
				printf("2: Waste\n");
				printf("0: Cancel move\n");
				scanf("%d", &option2);

				printf("Move card to where?\n");
				printf("1: Tableau\n");
				printf("2: Foundation\n");
				printf("0: Cancel move\n");
				scanf("%d", &option3);

				if( option2 == 1 && option3 == 1 )
				{
					printf("Source tableau?\n");
					scanf("%d", &input1);
					printf("Destination tableau?\n");
					scanf("%d", &input2);
					tmp = tableau[input1]->peek();
					tmp2 = tableau[input2]->peek();
					if( (tmp->getValue() == tmp2->getValue()-1) && (tmp->getSuit() == tmp2->getSuit()) )
					{
						tmp = tableau[input1]->pop();
						tableau[input2]->push(tmp);
					}
					else
						printf("Invalid move\n");
				}
				else if( option2 == 1 && option3 == 2 )
				{
					printf("Source tableau?\n");
					scanf("%d", &input1);
					printf("Destination foundation?\n");
					scanf("%d", &input2);
					tmp = tableau[input1]->peek();
					if( tmp->getValue() == 1 && foundation[input2]->getListSize() == 0 )
					{
						tmp = tableau[input1]->pop();
						foundation[input2]->push(tmp);
					}
					else if( foundation[input2]->getListSize() > 0 )
					{
						tmp2 = foundation[input2]->peek();
						if( (tmp->getValue() == tmp2->getValue()+1) && (tmp->getSuit() == tmp2->getSuit()) )
						{
							tmp = tableau[input1]->pop();
							foundation[input2]->push(tmp);
						}
						else
							printf("Invalid move\n");
					}
					else
						printf("Invalid move\n");
				}
				else if( option2 == 2 && option3 == 1 )
				{
					if( waste->getListSize() > 0 )
					{
						printf("Destination tableau?\n");
						scanf("%d", &input1);
						tmp = waste->peek();
						tmp2 = tableau[input1]->peek();
						if( (tmp->getValue() == tmp2->getValue()-1) && (tmp->getSuit() == tmp2->getSuit()) )
						{
							tmp = waste->pop();
							tableau[input1]->push(tmp);
						}
						else
							printf("Invalid move\n");
					}
					else
						printf("Waste empty\n");
				}
				else if( option2 == 2 && option3 == 2 )
				{
					if( waste->getListSize() > 0 )
					{
						printf("Destination foundation?\n");
						scanf("%d", &input1);
						tmp = waste->peek();
						if( tmp->getValue() == 1 && foundation[input1]->getListSize() == 0 )
						{
							tmp = waste->pop();
							foundation[input1]->push(tmp);
						}
						else if( foundation[input1]->getListSize() > 0 )
						{
							tmp2 = foundation[input1]->peek();
							if( (tmp->getValue() == tmp2->getValue()+1) && (tmp->getSuit() == tmp2->getSuit()) )
							{
								tmp = waste->pop();
								foundation[input1]->push(tmp);
							}
							else
								printf("Invalid move\n");
						}
						else
							printf("Invalid move\n");
					}
					else
						printf("Waste empty\n");
				}
				break;

			case 0:
				inProgress = 0;
				break;

			default:
				printf("Invalid option.\n");
				break;
		}

		for( i = 0; i < 8; i++ )
		{
			if( foundation[i]->getListSize() == 13 )
				if( foundationComplete[i] == 0 )
				{
					numberComplete++;
					foundationComplete[i] = 1;
				}
		}

		printf("Foundations complete: %d\n", numberComplete);

		if( numberComplete == 8 )
			inProgress = 0;

		if( deck->getListSize() == 0 )
		{
			for( i = 0; i < 10; i++ )
			{
				tmp = waste->peek();
				tmp2 = tableau[i]->peek();
				if( (tmp->getValue() == tmp2->getValue()-1) && (tmp->getSuit() == tmp2->getSuit()) )
					moveArray[0] = 1;
			}

			for( i = 0; i < 8; i++ )
			{
				tmp = waste->peek();
				if( foundation[i]->getListSize() > 0 )
				{
					tmp2 = foundation[i]->peek();
					if( (tmp->getValue() == tmp2->getValue()+1) && (tmp->getSuit() == tmp2->getSuit()) )
						moveArray[1] = 1;
				}
				else if( tmp->getValue() == 1 )
					moveArray[1] = 1;
			}

			for( i = 0; i < 10; i++ )
			{
				for( j = 0; j < 10; j++ )
				{
					tmp = tableau[i]->peek();
					tmp2= tableau[j]->peek();
					if( (tmp->getValue() == tmp2->getValue()-1) && (tmp->getSuit() == tmp2->getSuit()) )
						moveArray[2] = 1;
				}

				for( j = 0; j < 8; j++ )
				{
					tmp = tableau[i]->peek();
					if( foundation[j]->getListSize() > 0 )
					{
						tmp2= foundation[j]->peek();
						if( (tmp->getValue() == tmp2->getValue()+1) && (tmp->getSuit() == tmp2->getSuit()) )
							moveArray[3] = 1;
					}
					else if( tmp->getValue() == 1 )
						moveArray[3] = 1;
				}
			}

			if( moveArray[0] == 1 || moveArray[1] == 1 || moveArray[2] == 1 || moveArray[3] == 1 )
				inProgress = 1;
			else
				inProgress = 0;
		}

	} while( inProgress == 1 );

	if( numberComplete == 8 )
	{
		printf("\n+========================+\n");
		printf("|  much congratulations  |\n");
		printf("|so thief                |\n");
		printf("|         wow            |\n");
		printf("|            very win    |\n");
		printf("|    such card           |\n");
		printf("|                    wow |\n");
		printf("+========================+\n");
	}
	else
	{
		printf("\n+========================+\n");
		printf("|       much loser       |\n");
		printf("|             so robbed  |\n");
		printf("|         wow            |\n");
		printf("|very loss               |\n");
		printf("|            such bad    |\n");
		printf("|        wow             |\n");
		printf("+========================+\n");
	}


	return 0;
}
