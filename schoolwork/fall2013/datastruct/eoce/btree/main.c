#include <stdio.h>
#include "btree.h"

int main()
{
	int input, option;

	Node *tmp;

	printf("Enter a root value for the tree\n");
	scanf("%d", &input);
	Node *root = mkNode(input);

	do
	{
		printf("Choose an option\n");
		printf("1: Insert value into tree\n");
		printf("2: Remove value from tree\n");
		printf("3: Search tree\n");
		printf("4: Display tree\n");
		printf("5: Display values\n");
		printf("0: Quit\n");
		scanf("%d", &option);

		switch( option )
		{
			case 1:
				printf("Enter a value to insert\n");
				scanf("%d", &input);
				insert(input, root);
				break;

			case 2:
				printf("Enter a value to remove\n");
				scanf("%d", &input);
				remove(input, root);
				break;

			case 3:
				printf("Enter a value to search for\n");
				scanf("%d", &input);
				tmp = search(input, root);
				if( tmp == NULL )
					printf("Value not found in tree\n");
				else
					printf("Value exists in tree\n");
				break;

			case 4:
				displayTree(root);
				printf("\n");
				break;

			case 5:
				displayValue(root);
				printf("\n");

			case 0:
				break;

			default:
				printf("Invalid option.\n");
				break;
		}
	}while( option != 0 );

	return 0;
}
