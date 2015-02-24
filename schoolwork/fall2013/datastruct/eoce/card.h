#ifndef _FREECELL_H
#define _FREECELL_H

struct card
{
	int value;
	char suit;
	struct card *next;
	struct card *prev;
};

typedef struct card Card;

struct list
{
	struct card *start;
	struct card *end;
	int qty;
};

typedef struct list List;

struct stack
{
	struct list *data;
	struct card *top;
	int size;
};

typedef struct stack Stack;

Card *mkCard(int, char);
List *mkList();
List *append(Card*);
List *insert(Card*);
List *getCard(Card*);
Stack *mkStack(int);




#endif
