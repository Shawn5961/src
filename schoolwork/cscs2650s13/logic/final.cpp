#include <stdio.h>
#include "LOGIC.hpp"

/*
1: D: and, or, not
2: C: RSLatch
3: B: JKFlipFlop
4: A: 
*/

int main()
{
	char a = '1', b = '1', c = '0', d = '0', e;
	Logic logicTester;
	
	e = logicTester.NOT(logicTester.AND(b, logicTester.OR(c, a)));
	printf("#1: %c\n", e);

	logicTester.NANDL(c, b);
	printf("\n#2.1: %c\n", logicTester.getQ());
	logicTester.NANDL(d, a);
	printf("#2.2: %c\n", logicTester.getQ());
	logicTester.NANDL(a, d);
	printf("#2.3: %c\n", logicTester.getQ());

	logicTester.JKFLIPFLOP(a, b, c);
	logicTester.JKFLIPFLOP(b, a, b);
	printf("\n#3.1: %c\n", logicTester.getQ());
	logicTester.JKFLIPFLOP(a, a, d);
	printf("#3.2: %c\n", logicTester.getQ());
	logicTester.JKFLIPFLOP(b, b, a);
	printf("#3.3: %c\n", logicTester.getQ());
}
