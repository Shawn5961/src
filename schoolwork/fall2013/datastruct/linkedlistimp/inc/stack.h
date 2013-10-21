#ifndef _STACK_H
#define _STACK_H

#include "list.h"

struct stack {
	List *data;
	Node *top;
	int size;
};
typedef struct stack Stack;

Stack *mkstack(int);
Stack *push   (Stack *, Node *);
Node  *pop    (Stack **);
Node  *peek   (Stack *);

#endif
