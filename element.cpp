#include "element.h"
#include "drawing.h"
#include "constants.h"
#include "structures.h"


void Element::draw_sprite(class Draw* draw)
{
	draw->draw_surface(actual_sprite, position);
}

struct SDL_Surface* Element::get_sprite()
{
	return actual_sprite;
}

int Element::get_pos_x()
{
	return position.x;
}

int Element::get_pos_y()
{
	return position.y;
}

SDL_Rect* Element::get_hit_box_address()
{
	return &hit_box;
}