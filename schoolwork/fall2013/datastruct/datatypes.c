#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/*
 * signed short int
 * unsigned short int
 * signed int
 * unsigned int
 * signed long int
 * unsigned long int
 * signed long long int
 * unsigned long long int
 * float
 * double
 * long double
 * boolean
 */

int main()
{
	signed char sc = 0;
	unsigned char uc = 0;
	signed short int ssi = 0;
	unsigned short int usi = 0;
	signed int si = 0;
	unsigned int ui = 0;
	signed long int sli = 0;
	unsigned long int uli = 0;
	signed long long int slli = 0;
	unsigned long long int ulli = 0;
	float f = 0.0;
	double d = 0.0;
	long double ld = 0.0;
	_Bool b = 0;

	printf("A signed char is %hhu bytes\n", sizeof(sc));
	printf("Lower bound is: %hhd\n", ((unsigned char)(sc - 1)/2)+1);
	printf("Upper bound is: %hhd\n", ((unsigned char)(sc - 1)/2));

	printf("---------------------------\n");

	printf("An unsigned char is %hhu bytes\n", sizeof(uc));
	printf("Lower bound is: %hhu\n", uc);
	printf("Upper bound is: %hhu\n", uc - 1);

	printf("---------------------------\n");

	printf("A signed short int is %hhu bytes\n", sizeof(ssi));
	printf("Lower bound is: %hd\n", ((unsigned short int)(ssi - 1)/2)+1);
	printf("Upper bound is: %hd\n", ((unsigned short int)(ssi - 1)/2));

	printf("---------------------------\n");

	printf("An unsigned short int is %hhu bytes\n", sizeof(usi));
	printf("Lower bound is: %hu\n", usi);
	printf("Upper bound is: %hu\n", usi - 1);

	printf("---------------------------\n");

	printf("A signed int is %hhu bytes\n", sizeof(si));
	printf("Lower bound is: %d\n", ((unsigned int)(si - 1)/2)+1);
	printf("Upper bound is: %d\n", ((unsigned int)(si - 1)/2));

	printf("---------------------------\n");

	printf("An unsigned int is %hhu bytes\n", sizeof(ui));
	printf("Lower bound is: %u\n", ui);
	printf("Upper bound is: %u\n", ui - 1);

	printf("---------------------------\n");

	printf("A signed long int is %hhu bytes\n", sizeof(sli));
	printf("Lower bound is: %ld\n", ((unsigned long int)(sli - 1)/2)+1);
	printf("Upper bound is: %ld\n", ((unsigned long int)(sli - 1)/2));

	printf("---------------------------\n");

	printf("An unsigned long int is %hhu bytes\n", sizeof(uli));
	printf("Lower bound is: %lu\n", uli);
	printf("Upper bound is: %lu\n", uli - 1);

	printf("---------------------------\n");

	printf("A signed long long int is %hhu bytes\n", sizeof(slli));
	printf("Lower bound is: %lld\n", ((unsigned long long int)(slli - 1)/2)+1);
	printf("Upper bound is: %lld\n", ((unsigned long long int)(slli - 1)/2));

	printf("---------------------------\n");

	printf("An unsigned long long int is %hhu bytes\n", sizeof(ulli));
	printf("Lower bound is: %llu\n", ulli);
	printf("Upper bound is: %llu\n", ulli - 1);

	printf("---------------------------\n");

	printf("A float is %hhu bytes\n", sizeof(f));
	printf("Lower bound is: %e\n", FLT_MIN);
	printf("Upper bound is: %e\n", FLT_MAX);

	printf("---------------------------\n");

	printf("A double is %hhu bytes\n", sizeof(d));
	printf("Lower bound is: %e\n", DBL_MIN);
	printf("Upper bound is: %e\n", DBL_MAX);

	printf("---------------------------\n");

	printf("A long double is %hhu bytes\n", sizeof(ld));
	printf("Lower bound is: %e\n", LDBL_MIN);
	printf("Upper bound is: %e\n", LDBL_MAX);

	printf("---------------------------\n");

	printf("A boolean is %hhu bytes\n", sizeof(b));
	printf("Lower bound is: False\n");
	printf("Upper bound is: True\n");

	printf("---------------------------\n");

	return 0;
}
