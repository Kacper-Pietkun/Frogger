#ifndef point_manager_h
#define point_manager_h

#include "constants.h"

class Point_manager
{
private:
	int points;
	int high_scores_points[AMOUNT_OF_HIGH_SCORES];
	char high_scores_names[AMOUNT_OF_HIGH_SCORES][LETTERS_MAX_PLAYER_NICK];

public:
	Point_manager(int p = 0);
	void save_score(char* player_nick);
	void get_high_scores();
	void add_points(int number);

	int get_points();
	void set_points(int number);
};


#endif // point_manager_h

