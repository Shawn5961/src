#include "list.h"
#include <stdio.h>

void List :: displayf()
{
	Node *tmp;
	int i = 0;

	tmp = this -> start;

	while (tmp != NULL)
	{
		fprintf(stdout, "[%u] %u -> ", i, tmp -> getValue());
		i = i + 1;
		tmp = tmp->getNext();
	}

	fprintf(stdout, "NULL\n");
}

void List :: displayb()
{
	Node *tmp;
	int i = 0;

	tmp = this -> end;

	while (tmp != NULL)
	{
		i = i + 1;
		tmp = tmp->getPrev();
	}
	
	tmp = this -> end;

	while (tmp != NULL)
	{
		fprintf(stdout, "[%u] %u -> ", i, tmp -> getValue());
		tmp = tmp->getPrev();
		i--;
	}
	
	fprintf(stdout, "NULL\n");
}
