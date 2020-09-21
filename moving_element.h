#ifndef moving_element_h
#define moving_element_h
#include "element.h"
#include "player.h"

extern "C"
{
#include "SDL2-2.0.10/include/SDL.h"
#include "SDL2-2.0.10/include/SDL_main.h"
}

class Moving_element: public Element
{
protected:
	// It helps to create object on the one line one after another, not every object in the same position
	static int last_created_position_x;

	// How much ticks will object wait before it moves again
	float move_speed_delay;
	// How far will object move
	float move_speed;
	// variable to help count ticks before player moves again
	float passed;
	// if it is true then object moves left, if false it moves right
	bool going_left;

	// only for water objects
	// for example turtles cannot save player all the time because some of them dive
	bool can_save_player;

public:
	// Setting position of the object triggered after object is created
	void set_position(int pos_y, int draw_delta);
	// Triggers move_direction| It requires player because if moving element is tree_trunk or turtle then player moves with it
	void move(Player* player);
	// if direction is equal to left (-1) objects moves to the left, if right (1) objects moves to the right
	void move_direction(Player* player, int direction);
	// if moving element is outside of the map then we want him to ride virtual size of the map and then appear on the beginning of the map
	void loop_map_left();
	void loop_map_right();
	// Checks if player has jumped on this object
	bool check_collision_with_player(Player* player);

	void reset_last_created_pos_x();
};



#endif // moving_element_h

