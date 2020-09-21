#ifndef element_h
#define element_h

#include "structures.h"

extern "C"
{
#include "SDL2-2.0.10/include/SDL.h"
#include "SDL2-2.0.10/include/SDL_main.h"
}

class Element
{
protected:
	struct position_t position;
	struct SDL_Surface* actual_sprite;
	SDL_Rect hit_box;

public: 
	// FUNCTIONS
	// *****************************************
	void draw_sprite(class Draw* draw);
	// *****************************************


	// GET VARIABLES
	// *****************************************
	struct SDL_Surface* get_sprite();
	int get_pos_x();
	int get_pos_y();
	SDL_Rect* get_hit_box_address();
	// *****************************************
};

#endif // element_h

