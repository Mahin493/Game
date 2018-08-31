#ifndef HIGHSCORES_H_INCLUDED
#define HIGHSCORES_H_INCLUDED

int sortscore;
int highscore(int scores)
{
	FILE *high = fopen("Highscore.txt", "a");
	fprintf(high, "%d\n", s);
	fclose(high);

	high = fopen("Highscore.txt", "r");
	while (fscanf(high, "%d", &sortscore) != EOF)
	{
		if (sortscore > highScores)
			highScores = sortscore;
	}
	fclose(high);
	printf("High score:: %d\n", highScores);
	return highScores;
}

#endif // HIGHSCORES_H_INCLUDED
