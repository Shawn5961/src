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
	int qty;
};

typedef struct list List;

Node *mknode(int);
List *build();
List *mklist();
List *insert(List*, Node*, Node*);
List *getNode(List*, Node**);
Node *seek(List*, int);
List *qty(List*);
void displayf(List*);
void displayb(List*);
void debug();

#endif
