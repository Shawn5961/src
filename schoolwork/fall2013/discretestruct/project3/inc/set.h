#ifndef _SET_H
#define _SET_H

#include <cstdlib>

class Set
{
	public:
		Set();
		void printSet();
		void printSetPerm(int);
		void printSuperSet();
		void printPowerSet();
		void printSortedSet();
		void printReverseSortedSet();
		bool searchSet(int);
		int modSet();
		int modSet(int);
//		void sizeOfSet();
		int getSize();

	private:
		int set[100];
		int size;
};

#endif
