#include <stdio.h>
#include <stdlib.h>
#include "doublelist.h"

int main()
{
	int input, option;

	Node *nodePlace, *nodeValue;

	List *mylist = (List*)malloc(sizeof(List));

	do
	{
		printf("Choose an option\n");
		printf("1: Build list\n");
		printf("2: Insert node\n");
		printf("3: Get node\n");
		printf("8: Display forward\n");
		printf("9: Display backward\n");
		printf("0: Quit\n");
		scanf("%d", &option);

		switch( option )
		{
			case 1:
				mylist = build();
				break;

			case 2:
				printf("Enter a node to insert before: ");
				scanf("%d", &input);
				nodePlace = seek(mylist, input);

				printf("Enter a value to insert: ");
				scanf("%d", &input);
				nodeValue = (Node*)malloc(sizeof(Node));
				nodeValue->value = input;

				insert(mylist, nodePlace, nodeValue);
				break;
				
			case 3:
				printf("Enter a node to remove: ");
				scanf("%d", &input);
				nodePlace = seek(mylist, input);

				getNode(mylist, &nodePlace);
				break;

			case 8:
				displayf(mylist);
				break;

			case 9:
				displayb(mylist);
				break;

			default:
				break;
		}
	} while( option != 0 );
	
	printf("\nExiting program\n");

	return 0;
}
