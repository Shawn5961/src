#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
	struct node *prev;
};

typedef struct node Node;

struct list{
	struct node *start;
	struct node *end;
};

typedef struct list List;

List *build();
void displayf(List*);
void displayb(List*);

int main()
{
	List *mylist = (List*)malloc(sizeof(List));

	mylist = build();
	displayf(mylist);
	displayb(mylist);

	return 0;
}

List *build()
{
	List *mylist = (List*)malloc(sizeof(List));
	mylist->start = mylist->end = NULL;
	Node *tmp = NULL;

	int input = 0;

	printf("Enter a value (-1 to quit): ");
	scanf("%d", &input);

	while( input != -1 )
	{
		if( mylist->start == NULL )
		{
			mylist->start = mylist->end = (Node*)malloc(sizeof(Node));
			mylist->start->value = input;
			mylist->end->prev = mylist->start->next = NULL;
		}
		else
		{
			mylist->end->next = (Node*)malloc(sizeof(Node));
			mylist->end->next->value = input;
			mylist->end->next->next = NULL;
			mylist->end->next->prev = mylist->end;
			mylist->end = mylist->end->next;
		}

		printf("Enter a value (-1 to quit): ");
		scanf("%d", &input);
	}

	return mylist;
}

void displayf(List *mylist)
{
	Node *tmp = NULL;

	tmp = mylist->start;

	int input = 0;

	while( tmp != NULL )
	{
		printf("[%d] %d\n", input, tmp->value);
		tmp = tmp->next;
		input++;
	}
}


void displayb(List *mylist)
{
	Node *tmp = NULL;

	tmp = mylist->end;
	int input = 0;

	while( tmp != NULL )
	{
		tmp = tmp->prev;
		input++;
	}
	
	input--;

	tmp = mylist->end;

	while( tmp != NULL )
	{
		printf("[%d] %d\n", input, tmp->value);
		tmp = tmp->prev;
		input--;
	}
}

