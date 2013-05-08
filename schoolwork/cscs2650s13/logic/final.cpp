#include <stdio.h>
#include "LOGIC.hpp"

/*
1: D: and, or, not: +
2: C: RSLatch: - +
3: B: JKFlipFlop: 
4: A: 
*/

int main()
{
	char a = '-', b = '+', c = '-', d = '+', e;
	Logic logicTester;
	
	e = logicTester.NOT(logicTester.AND(b, logicTester.OR(c, d)));
	printf("#1: %c\n", e);

	printf("\nRSLatch\n");
	printf("S, R\n");
	logicTester.RSLATCH(a, b);
	printf("1, 0: %c\n", logicTester.getQ());
	logicTester.RSLATCH(b, c);
	printf("0, 1: %c\n", logicTester.getQ());

	logicTester.setQs('-', '+');
	logicTester.setQs2('-', '+');

	printf("\nJK Flip Flop\n");
	printf("J, K, Clk\n");
	logicTester.JKFLIPFLOP(b, d, a);
	printf("1, 1, 0: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("1, 1, 1: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(b, d, a);
	printf("1, 1, 0: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("1, 1, 1: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(b, d, a);
	printf("1, 1, 0: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("1, 1, 1: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(b, d, a);
	printf("1, 1, 0: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("1, 1, 1: %c\n", logicTester.getQ2());
}
