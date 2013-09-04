#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct person {
		char *name;
		int age;
		long int id;
	};

	typedef struct person Person;

	Person People[8];

	int i = 0;

	for ( i = 0; i < 8; i++)
	{
		printf("Enter person #%d's name: ", (i+1));
		People[i].name = (char*) malloc (sizeof(char)*20);
		scanf("%s", People[i].name);
		printf("Enter %s's age: ", People[i].name);
		scanf("%d", &People[i].age);
		printf("Enter %s's id number: ", People[i].name);
		scanf("%ld", &People[i].id);
	}

	i = -1;

	while ( i == -1 )
	{
		printf("Look up data for person #: ");
		scanf("%d", &i);
		if( !(( i >= 1) && (i <= 8)))
		{
			printf("Invalid person #. Try again!\n");
			i = -1;
		}
	}

	printf("Name: %s\n", People[i-1].name);
	printf("Age: %d\n", People[i-1].age);
	printf("ID: %ld\n", People[i-1].id);

	return 0;
}
