#ifndef _STACK_H
#define _STACK_H

#include "../doublelist.h"

struct stack{
	List *data;
	Node *top;
	int size;
}

typedef struct stack Stack;

Node *pop(Stack*);
Node *push(Stack*, Node*);
Stack *mkstack(int);
Node *peek(Stack*);

#endif
