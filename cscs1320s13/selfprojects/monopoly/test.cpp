#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "property.h"
#include "player.h"

int main()
{
	Player test;

	test.setName();
	printf("%s", test.getName());

	return 0;
}
