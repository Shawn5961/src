#include <stdio.h>
#include "LOGIC.h"

int main(int argc, char* argv[])
{
	char answer, answer2;
	
	answer = AND('1','1');
	answer2 = AND('1','5');

	printf("The AND of 1 and 1 is %c.", answer);
	printf("\nThe AND of 1 and 0 is %c.\n", answer2);

	return 0;
}
