#ifndef car_h
#define car_h

#include "structures.h"
#include "moving_element.h"

class Car: public Moving_element
{
private:
	int car_type;
	struct SDL_Surface* sprite[CAR_ANIMATE_SRPITES_MAX_NUMBER];

	int animatrion_status, animation_status_max; // animation_status is like iterator in for loop and animation_status_max is like its max value
	int max_animation; // max animations sprites
	int current_animation; // current animation sprite
public:
	~Car();
	// Setting properties like car model its speed, speed_delay, ...
	void set_car_properties(int route_y);
	int load_sprite();
	void animate();
	// checks if player touched car, if he did then player lose one of his lives
	void collide(Player* player, World* world);

};


#endif // car_h

