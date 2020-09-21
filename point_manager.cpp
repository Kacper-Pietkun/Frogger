#include "point_manager.h"
#include <stdio.h>
#include <string>

Point_manager::Point_manager(int p)
{
	points = p;
	for (int i = 0; i < AMOUNT_OF_HIGH_SCORES; i++)
	{
		strcpy(high_scores_names[i], "EMPTY");
		high_scores_points[i] = 0;
	}
}

void Point_manager::save_score(char* player_nick)
{
	// new_position will be equal to -1 if it is not big enogh to be saved in high score file
	int new_position = -1;

	// Searchong position for new score
	for (int i = 0; i < AMOUNT_OF_HIGH_SCORES; i++)
	{
		if (high_scores_points[i] < points)
		{
			new_position = i;
			break;
		}
	}
	// rearranging array to fit new score
	if (new_position != -1)
	{
		for (int i = AMOUNT_OF_HIGH_SCORES - 1; i >= 0; i--)
		{
			if (i == new_position)
			{
				if (strlen(player_nick) == 0)
					strcpy(high_scores_names[i], "...");
				else
					strcpy(high_scores_names[i], player_nick);
				high_scores_points[i] = points;
				break;
			}
			
			strcpy(high_scores_names[i], high_scores_names[i - 1]);
			high_scores_points[i] = high_scores_points[i - 1];
		}
		// Saving to file
		FILE* file;
		file = fopen(PATH_HIGH_SCORES, "w");

		if (file != NULL)
		{
			for (int i = 0; i < AMOUNT_OF_HIGH_SCORES; i++)
			{
				fprintf(file, "%s %d\n", high_scores_names[i], high_scores_points[i]);
			}
			fclose(file);
		}
	}

	
}

void Point_manager::get_high_scores()
{
	FILE* file;
	file = fopen(PATH_HIGH_SCORES, "r");

	char temp[LETTERS_MAX_PLAYER_NICK];

	if (file != NULL)
	{
		for (int i = 0; i < AMOUNT_OF_HIGH_SCORES; i++)
		{
			if (fscanf(file, "%s %d\n", temp, &high_scores_points[i]) <= 0)
				break;

			strcpy(high_scores_names[i], temp);
		}
		fclose(file);
	}
}

void Point_manager::add_points(int number)
{
	points += number;
}

int Point_manager::get_points()
{
	return points;
}

void Point_manager::set_points(int number)
{
	points = number;
}