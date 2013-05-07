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

	logicTester.NANDL(a, b);
	printf("\n#2.1: %c\n", logicTester.getQ());
	logicTester.NANDL(b, c);
	printf("#2.2: %c\n", logicTester.getQ());

	logicTester.setQs('-', '+');

	logicTester.JKFLIPFLOP(b, d, a);
	printf("\n#1, 1, 0: %c\n", logicTester.getQ());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("#1, 1, 1: %c\n", logicTester.getQ());
	logicTester.JKFLIPFLOP(b, d, a);
	printf("\n#1, 1, 0: %c\n", logicTester.getQ());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("#1, 1, 1: %c\n", logicTester.getQ());
	logicTester.JKFLIPFLOP(b, d, a);
	printf("\n#1, 1, 0: %c\n", logicTester.getQ());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("#1, 1, 1: %c\n", logicTester.getQ());
	logicTester.JKFLIPFLOP(b, d, a);
	printf("\n#1, 1, 0: %c\n", logicTester.getQ());
	logicTester.JKFLIPFLOP(d, b, b);
	printf("#1, 1, 1: %c\n", logicTester.getQ());
}
