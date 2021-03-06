#ifndef _STACK_H
#define _STACK_H

#include "../doublylinkedlist/doublelist.h"

struct stack{
	List *data;
	Node *top;
	int size;
};

typedef struct stack Stack;

Node *pop(Stack**);
Stack *push(Stack*, Node*);
Stack *mkstack(int);
Stack *peek(Stack*);

#endif
