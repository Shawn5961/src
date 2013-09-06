#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *next;
	};

typedef struct node Node;

int main()
{
	int input = 0;
	int seeker;

	Node *list, *tmp, *tmp2;

	list = tmp = tmp2 = NULL;

	while( input != -1 )
	{
		printf("Enter a value (-1 to end): ");
		scanf("%d", &input);
		
		if( input != -1)
		{
			if( list == NULL )
			{
				list = tmp = (Node*)malloc(sizeof(Node));
				tmp->next = NULL;
				list->value = input;
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

	tmp = list;
	input = 0;

	while( tmp != NULL )
	{
		printf("[%d] %d\n", input, tmp->value);
		tmp = tmp->next;
		input++;
	}

	printf("NULL\n");

	//Insert into list
	printf("Which node would you like to insert before: ");
	scanf("%d", &input);

	tmp = list;

	for( seeker = 0; seeker < (input-1); seeker++ )
		tmp = tmp->next;

	printf("Enter a value to insert: ");
	scanf("%d", &input);

	tmp2 = (Node*)malloc(sizeof(Node));
	tmp2->value = input;
	tmp2->next = tmp->next;
	tmp->next = tmp2;

	tmp = list;
	input = 0;
	
	while( tmp != NULL )
	{
		printf("[%d] %d\n", input, tmp->value);
		tmp = tmp->next;
		input++;
	}

	return(0);
}
