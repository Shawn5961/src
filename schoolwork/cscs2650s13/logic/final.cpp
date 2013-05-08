#include <stdio.h>
#include "LOGIC.hpp"

int main()
{
	char a = '1', b = '1', c = '0', d = '0', e;
	Logic logic;
	
	printf("NOT, AND, OR\n");
	e = logic.NOT(logic.AND(b, logic.OR(c, a)));
	printf("%c\n", e);

	//My RSLatch accepts arguments in the form of S, R
	printf("\nRSLatch\n");
	printf("S, R\n");
	logic.RSLATCH(e, b);
	printf("0, 1: %c\n", logic.getQ());
	logic.RSLATCH(d, a);
	printf("0, 1: %c\n", logic.getQ());
	logic.RSLATCH(a, d);
	printf("1, 0: %c\n", logic.getQ());

	//Reset Q's for Flip Flop
	printf("\nSetting Q values\n");
	logic.setQs('0', '1');
	printf(" q: %c,  qbar: %c\n", logic.getQ(), logic.getQBar());
	logic.setQs2('0', '1');
	printf("q2: %c, qbar2: %c\n", logic.getQ2(), logic.getQBar2());

	printf("\nJK Flip Flop\n");
	printf("J, K, Clk\n");
	logic.JKFLIPFLOP(a, b, c);
	printf("1, 1, 0: %c\n", logic.getQ2());
	logic.JKFLIPFLOP(b, a, b);
	printf("1, 1, 1: %c\n", logic.getQ2());
	logic.JKFLIPFLOP(a, a, d);
	printf("1, 1, 0: %c\n", logic.getQ2());
	logic.JKFLIPFLOP(b, b, a);
	printf("1, 1, 1: %c\n", logic.getQ2());
}
