#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i;
	char value = 0;

	switch(argc)
	{
		case 1:
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
			break;

		case 2:
			break;

		default:
			fprintf(stderr, "Additional arguments will be ignored.\n");
			break;
	}

	for (i = 0; i < strlen(*(argv+1)); i++)
	{
		value = *(*(argv+1)+i);
		switch(value)
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'w':
			case 'h':
			case 'y':
			break;

			case 's':
			case 'c':
				if ((*(*(argv+1)+(i+1))) == 'h')
					fprintf(stdout, "6");
				else
			case 'z':
				fprintf(stdout, "0");
				break;
	
			case 'd':
				if ((*(*(argv+1)+(i+1))) == 'g')
				{
					fprintf(stdout, "6");
					i++;
					break;
				}
				else
			case 't':
				if ((*(*(argv+1)+(i+1))) == 'c')
				{
					if ((*(*(argv+1)+(i+2))) == 'h')
					{
						fprintf(stdout, "6");
						i = i + 2;
						break;
					}
				}
				else
					fprintf(stdout, "1");
				break;

			case 'n':
				if (((*(*(argv+1)+(i+1))) == 'g') || ((*(*(argv+1)+(i+1))) == 'k'))
				{
					fprintf(stdout, "7");
					i++;
					break;
				}
				else
					fprintf(stdout, "2");
				break;

			case 'm':
				fprintf(stdout, "3");
				break;

			case 'r':
				fprintf(stdout, "4");
				break;

			case 'l':
				fprintf(stdout, "5");
				break;

			case 'j':
			case 'g':
				fprintf(stdout, "6");
				break;

			case 'k':
			case 'q':
			case 'x':
			case 'C':
				if ((*(*(argv+1)+(i+1))) == 'k')
					i++;
			case 'G':
				fprintf(stdout, "7");
				
				if (value == 'x')
					fprintf(stdout, "0");
				
				break;

			case 'f':
			case 'v':
				fprintf(stdout, "8");
				break;

			case 'p':
				if ((*(*(argv+1)+(i+1))) == 'h')
				{
					fprintf(stdout, "8");
					i++;
					break;
				}
			case 'b':
				fprintf(stdout, "9");
				break;

			default:
				fprintf(stdout, " ");
				break;
		}
	}

	fprintf(stdout, "\n");

	return(0);
}
