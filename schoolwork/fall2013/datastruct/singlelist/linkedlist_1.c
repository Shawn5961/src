#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *next;
	};
typedef struct node Node;

int main()
{
	int input=0;

	Node *list, *temp;

	list = temp = NULL;

	while( input != -1 )
	{
		printf("Enter a value (-1 to end): ");
		scanf("%d", &input);
		
		if( input != -1)
		{
			if( list == NULL )
			{
				list = temp = (Node*)malloc(sizeof(Node));
				temp->next = NULL;
				list->value = input;
			}
			else
			{
				temp->next = (Node*)malloc(sizeof(Node));
				temp->next->next = NULL;
				temp->next->value = input;
				temp = temp->next;
			}
		}
	}

	temp=list;

	while( temp != NULL )
	{
		printf("%d->", temp->value);
		temp = temp->next;
	}

	printf("NULL\n");

	return(0);
}
