/* A program written to accept two command line arguments,
   convert them to integers, and then add the arguments and
   display their result
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int num1, num2, sum;

	//Set the num1 and num2 variables equal to the command line arguments
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	//Set the int variable sum to the value of num1 + num2
	sum = num1 + num2;

	//Print the result of the calculation to the screen
	printf("The sum of %d and %d is %d.\n",num1,num2,sum);
	
	return 0;
}
