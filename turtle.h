#ifndef turtle_h
#define turtle_h

#include "structures.h"
#include "moving_element.h"

// Each element o f the game like forg, cars, turtles inherits from this virtual class
class Turtle : public Moving_element
{
private:
	int turtle_type;
	struct SDL_Surface* sprite[TURTLE_ANIMATE_SRPITES_MAX_NUMBER];

	int animatrion_status, animation_status_max; // animation_status is like iterator in for loop and animation_status_max is like its max value
	int max_animation;  // max animations sprites
	int current_animation; // current animation sprite

	// if this turtle dives not now but generally then it is true
	bool dives;

public:
	~Turtle();
	// SHORT, LONG - diffetent speed and sprite
	void set_turtle_type(int type, bool is_diving);
	int load_sprite();
	void animate();
};


#endif // turtle_h

