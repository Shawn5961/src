#ifndef _NODE_H
#define _NODE_H

#include <cstdlib>

class Node {
	public:
		Node();
		Node(int, char);
		Node *copy();
		int   getValue();
		char getSuit();
		Node *getNext();
		Node *getPrev();
		Node *getData();
		void  setNext(Node *);
		void  setPrev(Node *);
		void  setData(Node *);
		void  setValue(int);
		void setSuit(char);
		~Node();

	private:
		Node *next;
		Node *prev;
		Node *data;
		int value;
		char suit;
};

#endif
