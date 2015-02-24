#ifndef _QUEUE_H
#define _QUEUE_H

#include "list.h"

class Queue : protected List {
	public:
		Queue();
		Queue(int);
		void  enqueue(Node *);
		Node *dequeue();
		int   getBufferSize();
		void  setBufferSize(int);
		~Queue();

	private:
		List *data;
		Node *front;
		Node *back;
		int bufsiz;
};
#endif
