#ifndef _DOUBLELIST_H
#define _DOUBLELIST_H

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
List *insert(List*, Node*, Node*);
List *getNode(List*, Node**);
Node *seek(List*, int);
void displayf(List*);
void displayb(List*);
void debug();

#endif
