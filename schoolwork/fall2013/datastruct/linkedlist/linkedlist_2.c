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
List *appendList(List*);
List *insertList(List*);
List *removeList(List*);

int main()
{
	List *list = (List*)malloc(sizeof(List));

	int option;

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
		printf("4: Remove from list\n");
		printf("0: Quit\n");
		scanf("%d", &option);

		switch( option )
		{
			case 1:
				displayList(list);
				break;

			case 2:
				appendList(list);
				break;

			case 3:
				insertList(list);
				break;

			case 4:
				removeList(list);
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

List *appendList(List *list)
{
	Node *tmp, *tmp2 = NULL;

	tmp = list->start;

	int input = 0;

	printf("Enter a value to add: ");
	scanf("%d", &input);

	while( tmp->next != NULL )
		tmp = tmp->next;

	tmp2 = (Node*)malloc(sizeof(Node));
	tmp2->next = NULL;
	tmp2->value = input;
	tmp->next = tmp2;

	return list;
}

List *insertList(List *list)
{
	Node *tmp, *tmp2;

	tmp = tmp2 = list->start;

	int input = 0;
	int seeker;

	printf("Which node would you like to insert before: ");
	scanf("%d", &input);

	if( input != 0 )
	{
		for( seeker = 0; seeker < (input-1); seeker++ )
			tmp = tmp->next;

		printf("Enter a value to insert: ");
		scanf("%d", &input);

		tmp2 = (Node*)malloc(sizeof(Node));
		tmp2->value = input;
		tmp2->next = tmp->next;
		tmp->next = tmp2;
	}
	else if( input == 0 )
	{
		printf("Enter value for new node: ");
		scanf("%d", &input);

		tmp2 = (Node*)malloc(sizeof(Node));
		tmp2->value = input;
		tmp2->next = NULL;
		tmp2->next = tmp;
		list->start = tmp2;
	}
}

List *removeList(List *list)
{
	Node *tmp, *tmp2;

	tmp = tmp2 = list->start;

	int input = 0;
	int seeker, i;
	int counter = 0;

	printf("Which node would you like to remove: ");
	scanf("%d", &input);

/*	if( input != 0 )
	{
		for( seeker = 0; seeker < (input-1); seeker++ )
			tmp = tmp->next;

		tmp2 = (Node*)malloc(sizeof(Node));
		tmp2->value = input;
		tmp2->next = tmp->next;
		tmp->next = tmp2;
	}
*/	
	if( input == 0 )
	{
		while( tmp->next != NULL )
		{	
			tmp = tmp->next;
			counter++;
		}

		tmp = list->start;

		for( i = 0; i <= counter; i++)
		{
			if( tmp->next != NULL )
			{
				tmp->value = tmp->next->value;
				tmp = tmp->next;
			}
			else if( tmp->next == NULL )
			{
				tmp = NULL;
				free(tmp);
			}
		}
	}

	return list;
}
