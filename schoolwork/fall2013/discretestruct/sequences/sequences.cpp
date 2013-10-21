/* File: sequences.cpp
 * Author: Shawn Meas
 * Date: 10/9/2013
 * Purpose: This program demonstrates sequences, recurrence relations, and recursion
 */

#include <iostream>

using namespace std;

//Function prototype
void recurranceRelation(int, int);

int main()
{
	int aOf1 = 4;

	cout << "n is 1 and value is " << aOf1 << endl;
	
	recurranceRelation(aOf1, 1);

	return 0;
}

void recurranceRelation( int aOfN, int n)
{
	int aOfNPlusOne;

	aOfNPlusOne = aOfN + 2 * n + 3;

	cout << "n is " << ++n << " and value is " << aOfNPlusOne << endl;

	if( n < 5 )
		recurranceRelation( aOfNPlusOne, n);
}
