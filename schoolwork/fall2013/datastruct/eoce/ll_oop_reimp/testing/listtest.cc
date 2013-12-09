#include <stdio.h>
#include "list.h"

int main()
{
	int input, option, i;
	bool listExists = false;

	List *myList = new List();
	Node *gottenNode;

	do
	{
		printf("Please choose an option\n");
		printf("1: Build list\n");
		printf("2: Insert to list\n");
		printf("3: Append to list\n");
		printf("4: Get node from list\n");
		printf("5: Display forward\n");
		printf("6: Display backward\n");
		printf("7: Sort list\n");
		printf("8: Get size of list\n");
		printf("9: Destroy list\n");
		printf("0: Exit\n");

		scanf("%d", &option);

		switch( option )
		{
			case 1:
				{
					if( listExists == false )
					{
						printf("Please enter a value (-1 to quit)\n");
						scanf("%d", &input);
						while( input != -1 )
						{
							Node *tmp = new Node(input);
							myList->append((myList->getEnd()), tmp);
							printf("Please enter a value (-1 to quit)\n");
							scanf("%d", &input);
						}
						listExists = true;
					}
					else
						printf("List already exists. Please destroy before rebuilding\n");
					break;
				}

			case 2:
				{
					if( listExists == false )
						printf("No list exists. Please build before using\n");
					else
					{
						printf("Please enter a value to insert\n");
						scanf("%d", &input);
						Node *tmp = new Node(input);

						printf("Insert before which node?\n");
						scanf("%d", &input);
						Node *tmp2 = new Node();
						tmp2 = myList->getStart();

						for( i = 0; i < input; i++ )
							tmp2 = tmp2->getNext();

						myList->insert(tmp2, tmp);
					}
					break;
				}

			case 3:
				{
					if( listExists == false )
						printf("No list exists. Please build before using\n");
					else
					{
						printf("Please enter a value to append\n");
						scanf("%d", &input);
						Node *tmp = new Node(input);

						printf("Append which node?\n");
						scanf("%d", &input);
						Node *tmp2 = new Node();
						tmp2 = myList->getStart();

						for( i = 0; i < input; i++ )
							tmp2 = tmp2->getNext();

						myList->append(tmp2, tmp);
					}
					break;
				}

			case 4:
				{
					if( listExists == false )
						printf("No list exists. Please build before using\n");
					else
					{
						printf("Get which node?\n");
						scanf("%d", &input);
						Node *tmp = new Node();
						tmp = myList->getStart();

						for( i = 0; i < input; i++ )
							tmp = tmp->getNext();

						gottenNode = myList->getNode(tmp);
						printf("%d", gottenNode->getValue());
					}
					break;
				}

			case 5:
				if( listExists == false )
					printf("No list exists. Please build before using\n");
				else
				{
					printf("Displaying list forward\n");
					myList->displayf();
				}
				break;

			case 6:
				if( listExists == false )
					printf("No list exists. Please build before using\n");
				else
				{
					printf("Displaying list backward\n");
					myList->displayb();
				}
				break;

			case 7:
				if( listExists == false )
					printf("No list exists. Please build before using\n");
				else
				{
					printf("Sorting list\n");
					myList->sort();
				}
				break;

			case 8:
				if( listExists == false )
					printf("No list exists. Please build before using\n");
				else
					printf("Size of list: %d\n", myList->getQuantity());
				break;

			case 9:
				if( listExists == false )
					printf("No list exists. Please build before using\n");
				else
				{
					printf("Destroying list\n");
					myList->~List();
					listExists = false;
				}
				break;

			case 0:
				break;

			default:
				printf("Invalid option. Please reenter\n");
				break;
		}

	} while( option != 0 );

	return 0;
}
	
