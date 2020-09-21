#ifndef ending_spot_h
#define ending_spot_h

#include "structures.h"
#include "moving_element.h"
#include "structures.h"
#include "world.h"


class Ending_spot: public Element
{
private:

	char* sprite_lily_path;
	char* sprite_lily_busy_path; // if player has jumped on it
	struct SDL_Surface* sprite_lily;
	struct SDL_Surface* sprite_lily_busy;
	struct SDL_Surface* actual_sprite;
	// if busy equals true it means that player has already left frog at this spot
	bool busy;
public:
	static int spots_completed;
	static bool level_done;

	~Ending_spot();

	void set_properties(char* sprite, char* sprite_busy, position_t pos);
	int load_sprite();
	void draw_spot(Draw* draw);
	// Checking if player jumped on this spot and if he did it checks if player has jumped on it already
	void player_jumped(Player* player, World* world, Ending_spot spots[]);
	// Checking if player touched spot
	bool check_collision_with_player(Player* player);

	// Triggered after all spots are completed
	static void level_completed(Player* player, World* world, Ending_spot spots[], int spots_number);

	// if the spot is busy it has different sprite than when the spot is not busy, this function updates thus 
	void change_sprite();

	void set_busy(bool status);

	SDL_Surface* get_sprite_lily();
	SDL_Surface* get_sprite_lily_busy();
};


#endif // ending_spot_h

