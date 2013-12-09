#ifndef _STACK_H
#define _STACK_H

#include "list.h"

class Stack : protected List {
	public:
		Stack();
		Stack(int);
		void  push(Node *);
		Node *pop ();
		Node *peek();
		int   getSize();
		int   getListSize();
		void  setSize(int);
		~Stack();

	private:
		List *data;
		Node *top;
		int size;
};

#endif
