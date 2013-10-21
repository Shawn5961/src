#include "doublelist.h"
#include <stdio.h>
#include <stdlib.h>

Node *mknode(int value)
{
	Node *mynode = (Node*)malloc(sizeof(Node));
	mynode->prev = mynode->next = NULL;
	mynode->value = value;

	return mynode;
}

List *mklist()
{
	List *mylist = (List*)malloc(sizeof(List));
	mylist->start = mylist->end = NULL;

	return mylist;
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

	while( tmp->prev != NULL )
	{
		tmp = tmp->prev;
		input++;
	}
	
	tmp = mylist->end;

	while( tmp != NULL )
	{
		printf("[%d] %d\n", input, tmp->value);
		tmp = tmp->prev;
		input--;
	}
}

List *insert(List *mylist, Node *place, Node *newNode)
{
	if( place == mylist->start )
	{
		newNode->next = place;
		place->prev = newNode;
		newNode->prev = NULL;
		mylist->start = newNode;
	}
	else
	{
		newNode->next = place;
		place->prev->next = newNode;
		newNode->prev = place->prev;
		place->prev = newNode;
	}

	return mylist;
}


List *getNode(List *mylist, Node **place)
{
	if( *place == mylist->start )
	{
		mylist->start = mylist->start->next;
		mylist->start->prev = NULL;
		(*place)->next = NULL;
	}
	else if( *place == mylist->end )
	{
		mylist->end = mylist->end->prev;
		mylist->end->next = NULL;
		(*place)->prev = NULL;
	}
	else
	{
		(*place)->prev->next = (*place)->next;
		(*place)->next->prev = (*place)->prev;
		(*place)->prev = (*place)->next = NULL;
	}

	return mylist;
}

Node *seek(List *mylist, int input)
{
	Node *tmp = NULL;
	int seeker;

	tmp = mylist->start;

	if( input != 0 )
	{
		for( seeker = 0; seeker < input; seeker++ )
			tmp = tmp->next;
	}

	return tmp;
}

List *qty(List *mylist)
{
	Node *tmp = NULL;

	tmp = mylist->start;
	mylist->qty = 0;

	while( tmp->next != NULL )
	{
		mylist->qty++;
		tmp = tmp->next;
	}

	return mylist;
}
