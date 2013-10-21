#ifndef _LIST_H
#define _LIST_H

#include "node.h"

struct list {
	Node *start;
	Node *end;
	int qty;
};
typedef struct list List;

List *mklist();
List *insert(List *, Node *, Node *);
List *append(List *, Node *, Node *);
List *removeNode(List *, Node **);
void displayf(List *);
void displayb(List *);
List *clearlist(List *);
List *sortlist(List *);

#endif
