#ifndef _NODE_H
#define _NODE_H

#include <cstdlib>

class Node {
	public:
		Node();
		Node(int);
		Node *copy();
		int   getValue();
		Node *getNext();
		Node *getPrev();
		Node *getData();
		void  setNext(Node *);
		void  setPrev(Node *);
		void  setData(Node *);
		void  setValue(int);
		~Node();

	private:
		Node *next;
		Node *prev;
		Node *data;
		int value;
};

#endif
