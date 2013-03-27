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

	printf("1 NAND 1: %c\n", logicTester.NAND('1', '1'));
	printf("1 NAND 0: %c\n", logicTester.NAND('1', '0'));
	printf("0 NAND 1: %c\n", logicTester.NAND('0', '1'));
	printf("0 NAND 0: %c\n", logicTester.NAND('0', '0'));

	printf("\n1 NOR 1: %c\n", logicTester.NOR('1', '1'));
	printf("1 NOR 0: %c\n", logicTester.NOR('1', '0'));
	printf("0 NOR 1: %c\n", logicTester.NOR('0', '1'));
	printf("0 NOR 0: %c\n", logicTester.NOR('0', '0'));

	printf("\n1 XOR 1: %c\n", logicTester.XOR('1', '1'));
	printf("1 XOR 0: %c\n", logicTester.XOR('1', '0'));
	printf("0 XOR 1: %c\n", logicTester.XOR('0', '1'));
	printf("0 XOR 0: %c\n", logicTester.XOR('0', '0'));

	printf("\n1 HALFSUM 1: %c\n", logicTester.HALFSUM('1', '1'));
	printf("1 HALFSUM 0: %c\n", logicTester.HALFSUM('1', '0'));
	printf("0 HALFSUM 1: %c\n", logicTester.HALFSUM('0', '1'));
	printf("0 HALFSUM 0: %c\n", logicTester.HALFSUM('0', '0'));

	printf("\n1 HALFCARRY 1: %c\n", logicTester.HALFCARRY('1', '1'));
	printf("1 HALFCARRY 0: %c\n", logicTester.HALFCARRY('1', '0'));
	printf("0 HALFCARRY 1: %c\n", logicTester.HALFCARRY('0', '1'));
	printf("0 HALFCARRY 0: %c\n", logicTester.HALFCARRY('0', '0'));

	printf("\n1 FULLSUM 1 CARRY 1: %c\n", logicTester.FULLSUM('1', '1', '1'));
	printf("1 FULLSUM 1 CARRY 0: %c\n", logicTester.FULLSUM('1', '1', '0'));
	printf("1 FULLSUM 0 CARRY 1: %c\n", logicTester.FULLSUM('1', '0', '1'));
	printf("1 FULLSUM 0 CARRY 0: %c\n", logicTester.FULLSUM('1', '0', '0'));
	printf("0 FULLSUM 1 CARRY 1: %c\n", logicTester.FULLSUM('0', '1', '1'));
	printf("0 FULLSUM 1 CARRY 0: %c\n", logicTester.FULLSUM('0', '1', '0'));
	printf("0 FULLSUM 0 CARRY 1: %c\n", logicTester.FULLSUM('0', '0', '1'));
	printf("0 FULLSUM 0 CARRY 0: %c\n", logicTester.FULLSUM('0', '0', '0'));

	printf("\n1 FULLCARRY 1 CARRY 1: %c\n", logicTester.FULLCARRY('1', '1', '1'));
	printf("1 FULLCARRY 1 CARRY 0: %c\n", logicTester.FULLCARRY('1', '1', '0'));
	printf("1 FULLCARRY 0 CARRY 1: %c\n", logicTester.FULLCARRY('1', '0', '1'));
	printf("1 FULLCARRY 0 CARRY 0: %c\n", logicTester.FULLCARRY('1', '0', '0'));
	printf("0 FULLCARRY 1 CARRY 1: %c\n", logicTester.FULLCARRY('0', '1', '1'));
	printf("0 FULLCARRY 1 CARRY 0: %c\n", logicTester.FULLCARRY('0', '1', '0'));
	printf("0 FULLCARRY 0 CARRY 1: %c\n", logicTester.FULLCARRY('0', '0', '1'));
	printf("0 FULLCARRY 0 CARRY 0: %c\n", logicTester.FULLCARRY('0', '0', '0'));

	printf("\nMULTIPLEX| a |x0 |x1 |out|\n");
	printf("--------------------------\n");
	printf("MULTIPLEX| 1 | 1 | 1 | %c |\n", logicTester.MULTIPLEX('1', '1', '1'));
	printf("MULTIPLEX| 0 | 1 | 1 | %c |\n", logicTester.MULTIPLEX('0', '1', '1'));
	printf("MULTIPLEX| 1 | 1 | 0 | %c |\n", logicTester.MULTIPLEX('1', '1', '0'));
	printf("MULTIPLEX| 0 | 1 | 0 | %c |\n", logicTester.MULTIPLEX('0', '1', '0'));
	printf("MULTIPLEX| 1 | 0 | 1 | %c |\n", logicTester.MULTIPLEX('1', '0', '1'));
	printf("MULTIPLEX| 0 | 0 | 1 | %c |\n", logicTester.MULTIPLEX('0', '0', '1'));
	printf("MULTIPLEX| 1 | 0 | 0 | %c |\n", logicTester.MULTIPLEX('1', '0', '0'));
	printf("MULTIPLEX| 0 | 0 | 0 | %c |\n", logicTester.MULTIPLEX('0', '0', '0'));

	return 0;

}
