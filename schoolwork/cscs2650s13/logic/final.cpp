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

	logicTester.RSLATCH(a, b);
	printf("\n#2.1: %c\n", logicTester.getQ());
	logicTester.RSLATCH(b, c);
	printf("#2.2: %c\n", logicTester.getQ());

	logicTester.setQs('-', '+');
	logicTester.setQs2('-', '+');

	logicTester.JKFLIPFLOP(b, d, a);
	printf("#1, 1, 0: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("#1, 1, 1: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(b, d, a);
	printf("#1, 1, 0: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("#1, 1, 1: %c\n", logicTester.getQ2());
	getchar();
	logicTester.JKFLIPFLOP(b, d, a);
	printf("#1, 1, 0: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("#1, 1, 1: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(b, d, a);
	printf("#1, 1, 0: %c\n", logicTester.getQ2());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("#1, 1, 1: %c\n", logicTester.getQ2());
}
