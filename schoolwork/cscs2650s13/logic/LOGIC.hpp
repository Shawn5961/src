#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

#define TRUESTATE '+'
#define FALSESTATE '-'
#define INVALID 'x' 


class Logic{
	char in1, in2, in3, result, sum, carry;
	char a, x0, x1, x; 
	char s, r, q, qbar;
	char out0, out1;
	char clk;
	char tmp1, tmp2;
	int clkGen;
public:
	char AND(char, char);
	char OR(char, char);
	char NOT(char);
	char NAND(char, char);
	char NOR(char, char);
	char XOR(char, char);
	char HALFSUM(char, char);
	char HALFCARRY(char, char);
	char FULLSUM(char, char, char);
	char FULLCARRY(char, char, char);
	char MULTIPLEX(char, char, char);
	char VAND(int, ...);
	char getOut0();
	char getOut1();
	char getQ();
	char getQBar();
	void DEMUX(char, char);
	void NANDL(char, char);
	void NORL(char, char);
	char CLOCK();
	char getCLOCK();
	void CLOCKRSNAND(char, char, char);
	void EDGEFLIPFLOP(char, char, char);
	void JKFLIPFLOP(char, char, char);
	void DLATCH(char, char);
	void DFLIPFLOP(char, char);
};

char Logic::AND(char in1, char in2)
{
	if(in1 == TRUESTATE)
	{
		if (in2 == TRUESTATE)
		{
			result = TRUESTATE;
		}
		else if (in2 == FALSESTATE)
		{
			result = FALSESTATE;
		}
		else
		{
			result = INVALID;
		}
	}
	else if(in1 == FALSESTATE)
	{
		result = FALSESTATE;
	}
	else
	{
		result = INVALID;
	}

	return result;
}

char Logic::OR(char in1, char in2)
{
	if(in1 == TRUESTATE)
	{
		result = TRUESTATE;
	}
	else if (in1 == FALSESTATE)
	{
		if (in2 == TRUESTATE)
		{
			result = TRUESTATE;
		}
		else if (in2 == FALSESTATE)
		{
			result = FALSESTATE;
		}
		else
		{
			result = INVALID;
		}
	}
	else
	{
		result = INVALID;
	}

	return result;
}

char Logic::NOT(char in1)
{
	if(in1 == TRUESTATE)
	{
		result = FALSESTATE;
	}
	else if(in1 == FALSESTATE)
	{
		result = TRUESTATE;
	}
	else
	{
		result = INVALID;
	}

	return result;
}

char Logic::NAND(char in1, char in2)
{
	result = NOT(AND(in1, in2));

	return result;
}

char Logic::NOR(char in1, char in2)
{
	result = NOT(OR(in1, in2));

	return result;
}

char Logic::XOR(char in1, char in2)
{
	result = OR(AND(NOT(in1), in2), AND(in1, NOT(in2)));

	return result;
}

char Logic::HALFSUM(char in1, char in2)
{
	sum = XOR(in1, in2);

	return sum;
}

char Logic::HALFCARRY(char in1, char in2)
{
	carry = AND(in1, in2);

	return carry;
}

char Logic::FULLSUM(char in1, char in2, char in3)
{
	sum = XOR(XOR(in1, in2), in3);

	return sum;
}

char Logic::FULLCARRY(char in1, char in2, char in3)
{
	carry = OR(AND(XOR(in1, in2), in3), AND(in1, in2));

	return carry;
}

char Logic::MULTIPLEX(char a, char x0, char x1)
{
	x = OR(AND(NOT(NOT(a)), x1), AND(NOT(a), x0));

	return x;
}

char Logic::VAND(int numArgs, ...)
{
	va_list args;
	va_start(args, numArgs);
	
	char arg, result;
	int i;
	for(i = numArgs; i > 0; i--)
	{
		arg = va_arg(args, int);
		if(i == numArgs)
		{
			result = arg;
		}
		else
		{
			result = AND(result, arg);
		}
	}

	va_end(args);

	return result;
}

char Logic::getOut0()
{
	return out0;
}

char Logic::getOut1()
{
	return out1;
}
	
char Logic::getQ()
{
	return q;
}

char Logic::getQBar()
{
	return qbar;
}

void Logic::DEMUX(char a, char in1)
{
	out0 = AND(NOT(a), in1);
	out1 = AND(NOT(NOT(a)), in1);
}

void Logic::NANDL(char s, char r)
{
	if(s == FALSESTATE)
	{
		if(r == FALSESTATE)
		{
			q = TRUESTATE;
			qbar = TRUESTATE;
		}
		else
		{
			q = TRUESTATE;
			qbar = NAND(r, q);
		}
	}
	else if(r == FALSESTATE)
	{
		qbar = TRUESTATE;
		q = NAND(s, qbar);
	}
}

void Logic::NORL(char s, char r)
{
	if(s == TRUESTATE)
	{
		if(r == TRUESTATE)
		{
			q = FALSESTATE;
			qbar = FALSESTATE;
		}
		else
		{
			q = TRUESTATE;
			qbar = NOR(r, q);
		}
	}
	else if(r == TRUESTATE)
	{
		qbar = TRUESTATE;
		q = NOR(s, qbar);
	}
}

char Logic::CLOCK()
{
	clkGen = (rand () % 2);

	if(clkGen == 0)
	{
		clk = FALSESTATE;
	}
	else if(clkGen == 1)
	{
		clk = TRUESTATE;
	}
	else
	{
		clk = INVALID;
	}

	return clk;
}

char Logic::getCLOCK()
{
	return clk;
}

//Fix stuff below here.
void Logic::CLOCKRSNAND(char s, char r, char clock)
{
	s = NAND(s, clock);
	r = NAND(r, clock);

	NANDL(s, r);
}

void Logic::EDGEFLIPFLOP(char s, char r, char clock)
{
	CLOCKRSNAND(s, r, clock);
	CLOCKRSNAND(getQ(), getQBar(), NOT(clock));
}

void Logic::JKFLIPFLOP(char j, char k, char clock)
{
	tmp1 = NOT(VAND(3, j, clock, getQBar()));
	tmp2 = NOT(VAND(3, k, clock, getQ()));
	NANDL(tmp1, tmp2);
	CLOCKRSNAND(getQ(), getQBar(), NOT(clock));
}

void Logic::DLATCH(char d, char clock)
{
	tmp1 = NAND(d, clock);
	tmp2 = NAND(NOT(tmp1), clock);

	NANDL(tmp1, tmp2);
}

void Logic::DFLIPFLOP(char d, char clock)
{
	DLATCH(d, clock);
	CLOCKRSNAND(getQ(), getQBar(), NOT(clock));
}
