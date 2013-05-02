#ifndef _DIRT_H
#define _DIRT_H

#include <iostream>

class dirt 
{
	public:
		int digFlag;
		dirt();
		void init(int);
		void clear();
		void dig(int, int);
		void set(int, int, int);
		int get(int, int);

	private:
		int grid[18][30];
};

#endif
