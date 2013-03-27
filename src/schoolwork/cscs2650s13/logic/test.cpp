#include <stdio.h>
#include "LOGIC.hpp"

int main()
{
	Logic logicTester;

	printf("1 AND 1: %c\n", logicTester.AND('1', '1'));
	printf("1 AND 0: %c\n", logicTester.AND('1', '0'));
	printf("0 AND 1: %c\n", logicTester.AND('0', '1'));
	printf("0 AND 0: %c\n", logicTester.AND('0', '0'));

	printf("\n1 OR 1: %c\n", logicTester.OR('1', '1'));
	printf("1 OR 0: %c\n", logicTester.OR('1', '0'));
	printf("0 OR 1: %c\n", logicTester.OR('0', '1'));
	printf("0 OR 0: %c\n", logicTester.OR('0', '0'));

	printf("\nNOT 1: %c\n", logicTester.NOT('1'));
	printf("NOT 0: %c\n", logicTester.NOT('0'));

	return 0;
}
