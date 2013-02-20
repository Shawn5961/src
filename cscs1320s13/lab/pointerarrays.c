#include <stdio.h>
#include <stdlib.h>

#define NUM_SCORES 5
#define SCORE0 87
#define SCORE1 92
#define SCORE2 97
#define SCORE3 83
#define SCORE4 79

int main()
{
	unsigned char *scores;
	float average;

	scores = (unsigned char *) malloc (sizeof(unsigned char) * NUM_SCORES);
	*(scores+0) = SCORE0;
	*(scores+1) = SCORE1;
	*(scores+2) = SCORE2;
	*(scores+3) = SCORE3;
	*(scores+4) = SCORE4;

	average = ((float)(scores[0] + scores[1] + scores[2] + scores[3] + scores[4]))/ NUM_SCORES;

	fprintf(stdout, "Score 1: %d\n", SCORE0);
	fprintf(stdout, "Score 2: %d\n", SCORE1);
	fprintf(stdout, "Score 3: %d\n", SCORE2);
	fprintf(stdout, "Score 4: %d\n", SCORE3);
	fprintf(stdout, "Score 5: %d\n", SCORE4);
	fprintf(stdout, "Average: %.2f\n", average);

	return 0;
}
