#include <stdio.h>
#include "STATES.h"
#include "NOT.h"
#include "OR.h"
#include "AND.h"

int main(int argc, char **argv)
{
	trueState = **(argv+1);
	falseState = **(argv+2);

	if (argc <= 2)
	{
		printf("\nNot enough arguments defined. You must define two arguments.\n");
	}
	else if (argc > 3)
	{
		printf("\nToo many arguments defined. You must define two arguments.\n");
	}
	else
	{
		printf("\nNOT %c: %c\n",trueState,NOT(trueState));
		printf("NOT %c: %c\n",falseState,NOT(falseState));

		printf("\n%c AND %c: %c\n",trueState, trueState, AND(trueState,trueState));
		printf("%c AND %c: %c\n",trueState, falseState, AND(trueState,falseState));
		printf("%c AND %c: %c\n",falseState, trueState, AND(falseState,trueState));
		printf("%c AND %c: %c\n",falseState, falseState, AND(falseState,falseState));

		printf("\n%c OR %c: %c\n",trueState, trueState, OR(trueState,trueState));
		printf("%c OR %c: %c\n",trueState, falseState, OR(trueState,falseState));
		printf("%c OR %c: %c\n",falseState, trueState, OR(falseState,trueState));
		printf("%c OR %c: %c\n",falseState, falseState, OR(falseState,falseState));

		printf("\n%c XOR %c: %c\n",trueState, trueState, OR(AND(trueState,NOT(trueState)),AND(NOT(trueState),trueState)));
		printf("%c XOR %c: %c\n",trueState, falseState, OR(AND(trueState,NOT(falseState)),AND(NOT(trueState),falseState)));
		printf("%c XOR %c: %c\n",falseState, trueState, OR(AND(falseState,NOT(trueState)),AND(NOT(falseState),trueState)));
		printf("%c XOR %c: %c\n",falseState, falseState, OR(AND(falseState,NOT(falseState)),AND(NOT(falseState),falseState)));
	}

	return 0;
}
