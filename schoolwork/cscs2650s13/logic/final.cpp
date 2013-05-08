#include <stdio.h>
#include "LOGIC.hpp"

int main()
{
	char a = '1', b = '1', c = '0', d = '0', e;
	Logic logicTester;
	
	e = logicTester.NOT(logicTester.AND(b, logicTester.OR(c, a)));
	printf("#1: %c\n", e);

	//My RSLatch accepts arguments in the form of S, R
	printf("\nRSLatch\n");
	printf("S, R\n");
	logicTester.RSLATCH(e, b);
	printf("0, 1: %c\n", logicTester.getQ());
	logicTester.RSLATCH(d, a);
	printf("0, 1: %c\n", logicTester.getQ());
	logicTester.RSLATCH(a, d);
	printf("1, 0: %c\n", logicTester.getQ());

	//Reset Q's for Flip Flop
	logicTester.setQs('0', '1');
	logicTester.setQs2('0', '1');

	printf("\nJK Flip Flop\n");
	printf("J, K, Clk\n");
	logicTester.JKFLIPFLOP(a, b, c);
	printf("1, 1, 0: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(b, a, b);
	printf("1, 1, 1: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(a, a, d);
	printf("1, 1, 0: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(b, b, a);
	printf("1, 1, 1: %c\n", logicTester.getQ2());
}
