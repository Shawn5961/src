#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i;
	char value = 0;

	if(argc == 1)
	{
		fprintf(stderr, "Error! Please provide word to encode ");
		fprintf(stderr, "on command-line.\n\n");
		fprintf(stderr, "Syntax is:\n");
		fprintf(stderr, "===================================\n");
		fprintf(stderr, "a,e,i,o,u,w,h,y .......... no value\n");
		fprintf(stderr, "s,c,z .................... 0\n");
		fprintf(stderr, "t,d,th ................... 1\n");
		fprintf(stderr, "n ........................ 2\n");
		fprintf(stderr, "m ........................ 3\n");
		fprintf(stderr, "r ........................ 4\n");
		fprintf(stderr, "l ........................ 5\n");
		fprintf(stderr, "ch,sh,g,j,dg,tch ......... 6\n");
		fprintf(stderr, "k,q,x,C,G,-ng,-nk ........ 7\n");
		fprintf(stderr, "f,v,ph ................... 8\n");
		fprintf(stderr, "p,b ...................... 9\n");
		fprintf(stderr, "===================================\n\n");
		exit(1);
	}
	else if(argc != 2)
	{
		fprintf(stderr, "Additional arguments will be ignored.\n");
	}

	for (i = 0; i < strlen(*(argv+1)); i++)
	{
		value = *(*(argv+1)+i);
		if(value == 'a' || value == 'e' || value == 'i' || value == 'o' || value == 'u' || value == 'w' || value == 'h' || value == 'y')
		{
		}

		else if(value == 's' || value == 'c' || value == 'z')
		{
			if ((value == 's' || value == 'c') && (*(*(argv+1)+(i+1))) == 'h')
			{
				fprintf(stdout, "6");
			}
			else
			{
				fprintf(stdout, "0");
			}
		}

		else if(value == 'd' || value == 't')
		{
			if (value == 'd' && (*(*(argv+1)+(i+1))) == 'g')
			{
				fprintf(stdout, "6");
				i++;
			}
			else if (value == 't' && (*(*(argv+1)+(i+1))) == 'c')
			{
				if ((*(*(argv+1)+(i+2))) == 'h')
				{
					fprintf(stdout, "6");
					i = i + 2;
				}
			}
			else
			{
				fprintf(stdout, "1");
			}
		}

		else if(value == 'n')
		{
			if (((*(*(argv+1)+(i+1))) == 'g') || ((*(*(argv+1)+(i+1))) == 'k'))
			{
				fprintf(stdout, "7");
				i++;
			}
			else
				fprintf(stdout, "2");
		}

		else if(value == 'm')
		{
			fprintf(stdout, "3");
		}

		else if(value == 'r')
		{
			fprintf(stdout, "4");
		}

		else if(value == 'l')
		{
			fprintf(stdout, "5");
		}

		else if(value == 'j' || value == 'g')
		{
			fprintf(stdout, "6");
		}

		else if(value == 'k' || value == 'q' || value == 'x' || value == 'C' || value == 'G')
		{
			if(value == 'k' || value == 'q' || value == 'x' || value == 'C')
			{
				if ((*(*(argv+1)+(i+1))) == 'k')
					i++;
			}

			fprintf(stdout, "7");
			
			if (value == 'x')
				fprintf(stdout, "0");
		}

		else if(value == 'f' || value == 'v')
		{
			fprintf(stdout, "8");
		}

		else if(value == 'p' || value == 'b')
		{
			if (value == 'p' && (*(*(argv+1)+(i+1))) == 'h')
			{
				fprintf(stdout, "8");
				i++;
			}
			else
			{
				fprintf(stdout, "9");
			}
		}

		else
		{
			fprintf(stdout, " ");
		}
	}

	fprintf(stdout, "\n");

	return(0);
}
