#include <stdio.h>

int main()
{
	int userNum;

	printf("Enter a number, bruh\n");
	scanf("%d", &userNum);

	if (userNum < 50)
	{
		printf("Hashtag swag, son\n");
	}
	else if (userNum == 50)
	{
		printf("Hashtag yolo, yahur?\n");
	}
	else
	{
		printf("Have some baconpancakes\n");
	}

	return 0;
}