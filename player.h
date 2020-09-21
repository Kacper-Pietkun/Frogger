#ifndef player_h
#define player_h

#include "drawing.h"
#include "element.h"
#include "world.h"
#include "point_manager.h"

class Player: public Element
{
private:
	int lives;
	int delta_move;
	bool safe_on_water;
	bool game_over;
	// Variables needed for points, everytime player is closer to the ending spot it gets 10 points
	int nearest_position, actual_position;
	Point_manager point_manager;

	// SPRITES
	struct SDL_Surface* sprite_up;
	struct SDL_Surface* sprite_up_move;
	struct SDL_Surface* sprite_down;
	struct SDL_Surface* sprite_down_move;
	struct SDL_Surface* sprite_right;
	struct SDL_Surface* sprite_right_move;
	struct SDL_Surface* sprite_left;
	struct SDL_Surface* sprite_left_move;

	// if player clicked key to move, then animation was triggered and until this animation is finished player cannot move
	direction_t direction;
	// animation status is like iterator for animating player sprite it will go form 0 to animation_max
	int animation_max;
	int animation_status;

public:
	Player(position_t position, int lives, int d_move, int width, int height);
	~Player();

	int load_sprites();

	// MOVING
	// *************************************************
	// Triggered after clicking arrows
	void move_vertical(bool left);
	void move_horizontal(bool up);

	// Triggered when player is moved by turtle or tree trunk
	void moved_by_element(int delta);
	// *************************************************

	// For adding points if player is closer to the ending spot
	void check_points_position();

	// Triggered if player loses his life
	void die();

	// Checking if player is safe on the water, if not player lose one of his lives
	void collide_with_water(class World* world);

	// Instructions which are triggered after player reach its destination (lily)
	void spot_completed();

	// restarting player's position and player's hitboxes to the beginning of the map
	void restart();

	void animate();

	// GETTING AND SETTING VARIABLES
	// *************************************************
	int get_pos_x();
	void set_pos_x(int pos);
	void set_pos_y(int pos);

	void set_safe_on_water(bool safe);
	bool get_safe_on_water();

	bool get_game_over();
	void set_game_over(bool status);

	int get_lives();
	void set_lives(int number_of_lives);

	direction_t get_direction();
	void set_direction(direction_t dir);

	Point_manager* get_point_manager_address();
	// *************************************************

};

#endif // player_h
