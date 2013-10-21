#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *next;
	};

typedef struct node Node;

struct list{
	struct node *start;
};

typedef struct list List;

List *build();
void displayList(List*);
List *appendList(List*, int);
List *insertList(List*, int, int);
List *removeNode(List*, int);
List *clearList(List*);
List *sortList(List*);

int main()
{
	List *list = (List*)malloc(sizeof(List));

	int input, input2, option = 1;

	printf("Please initialize your linked list\n");
	list = build();

	displayList(list);

	while( option != 0 )
	{
		//Print menu for operations.
		printf("Please choose an operation\n");
		printf("1: Display list\n");
		printf("2: Append to list\n");
		printf("3: Insert into list\n");
		printf("4: Sort list\n");
		printf("5: Remove from list\n");
		printf("6: Clear list\n");
		printf("0: Quit\n");
		scanf("%d", &option);
		printf("\nmenudebug\n");

		switch( option )
		{
			case 1:
				displayList(list);
				break;

			case 2:
				printf("Enter a value to add: ");
				scanf("%d", &input);
				appendList(list, input);
				break;

			case 3:
				printf("Which node would you like to insert before: ");
				scanf("%d", &input);
				printf("Enter a value to insert: ");
				scanf("%d", &input2);
				insertList(list, input, input2);
				break;

			case 4:
				printf("\ncasedebug\n");
				sortList(list);
				break;

			case 5:
				printf("Which node would you like to remove: ");
				scanf("%d", &input);
				removeNode(list, input);
				break;

			case 6:
				clearList(list);
				break;

			case 0:
				break;

			default:
				printf("Invalid input. Please try again\n");
				break;
		}
	}
	
	return 0;
}

List *build()
{
	List *list = (List*)malloc(sizeof(List));
	list->start = NULL;
	Node *tmp = NULL;

	int input = 0;
	
	while( input != -1 )
	{
		printf("Enter a value (-1 to end): ");
		scanf("%d", &input);
		
		if( input != -1)
		{
			if( list->start == NULL )
			{
				list->start = tmp = (Node*)malloc(sizeof(Node));
				tmp->next = NULL;
				list->start->value = input;
			}
			else
			{
				tmp->next = (Node*)malloc(sizeof(Node));
				tmp->next->next = NULL;
				tmp->next->value = input;
				tmp = tmp->next;
			}
		}
	}

	return list;
}

void displayList(List *list)
{
	Node *tmp = NULL;

	tmp = list->start;

	int input = 0;

	while( tmp != NULL )
	{
		printf("[%d] %d\n", input, tmp->value);
		tmp = tmp->next;
		input++;
	}

	printf("NULL\n");
}

List *appendList(List *list, int input)
{
	Node *tmp, *tmp2 = NULL;

	tmp = list->start;

	while( tmp->next != NULL )
		tmp = tmp->next;

	tmp2 = (Node*)malloc(sizeof(Node));
	tmp2->next = NULL;
	tmp2->value = input;
	tmp->next = tmp2;

	return list;
}

List *insertList(List *list, int input, int input2)
{
	Node *tmp, *tmp2;

	tmp = tmp2 = list->start;

	int seeker;

	if( input != 0 )
	{
		for( seeker = 0; seeker < (input-1); seeker++ )
			tmp = tmp->next;

		tmp2 = (Node*)malloc(sizeof(Node));
		tmp2->value = input2;
		tmp2->next = tmp->next;
		tmp->next = tmp2;
	}
	else if( input == 0 )
	{
		tmp2 = (Node*)malloc(sizeof(Node));
		tmp2->value = input2;
		tmp2->next = NULL;
		tmp2->next = tmp;
		list->start = tmp2;
	}
}

List *removeNode(List *list, int input)
{
	Node *tmp, *tmp2;

	tmp = tmp2 = list->start;

	int seeker;
	int counter = 0;

	if( input == 0 )
	{
		tmp2 = list->start->next;
		free(list->start);
		list->start = tmp2;
	}
	else if( input != 0 )
	{
		for( seeker = 0; seeker < (input-1); seeker++ )
			tmp = tmp->next;
		
		tmp2 = tmp->next->next;
		free(tmp->next);
		tmp->next = tmp2;
	}
	

	return list;
}

List *clearList(List *list)
{
	Node *tmp, *tmp2;

	tmp = tmp2 = list->start;

	int seeker, seeker2, i, listMax = 0;

	while( tmp->next != NULL )
	{
		tmp = tmp->next;
		listMax++;
	}

	seeker2 = listMax;

	for( i = 0; i < listMax; i++ )
	{
		tmp = list->start;

		for( seeker = 0; seeker < (seeker2-1); seeker++ )
			tmp = tmp->next;
	
		tmp2 = tmp->next->next;
		free(tmp->next);
		tmp->next = tmp2;
		seeker2--;
	}

	tmp2 = list->start->next;
	free(list->start);
	list->start = tmp2;

	return list;
}

List *sortList(List *list)
{
	Node *tmp, *tmp2, *tmp3;

	tmp = tmp2 = tmp3 = list->start;
	
	int i, count = 0;
	int flag = 0;
	int tempint;

	while( tmp != NULL )
	{
		count++;
		tmp = tmp->next;
	}

	tmp = list->start;

	do
	{
		for( i = 0; i < (count-1); i++ )
		{
			if( tmp->value > tmp->next->value )
			{
				tempint = tmp->next->value;
				tmp->next->value = tmp->value;
				tmp->value = tempint;
			}

			tmp = tmp->next;
		}

		tmp = list->start;

		count--;
		
		if( count == 1 )
			flag = 1;

	} while( flag == 0 );


	return list;
}
