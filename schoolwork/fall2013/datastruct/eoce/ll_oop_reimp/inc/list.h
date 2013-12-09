#ifndef _LIST_H
#define _LIST_H

#include "node.h"

class List {
	public:
		List();
		void insert(Node *, Node *);
		void append(Node *, Node *);
		Node *getNode(Node *);
		void displayf();
		void displayb();
		void sort();
		int  getQuantity();
		~List();
		Node* getStart();
		Node* getEnd();

	private:
		Node *start;
		Node *end;
		int qty;
};

#endif
