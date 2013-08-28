#include "NOT.h"
#include "AND.h"
#include "OR.h"

char XOR(input1, input2)
{
	char result

	result = OR(AND(NOT(input1),input2),AND(input1),(NOT(input2)));

	return result;

}
