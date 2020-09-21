#include "turtle.h"
#include "constants.h"


Turtle::~Turtle()
{
	for (int i = 0; i < max_animation; i++)
	{
		SDL_FreeSurface(sprite[i]);
	}
}

void Turtle::set_turtle_type(int type, bool is_diving)
{
	turtle_type = type;
	dives = is_diving;
	if (turtle_type == TURTLE_SHORT)
	{
		move_speed = SPEED_TURTLE_SHORT;
		move_speed_delay = SPEED_DELAY_TURTLE_SHORT;
		hit_box.w = TURTLE_SHORT_WIDTH;
	}
	else if (turtle_type == TURTLE_LONG)
	{
		move_speed = SPEED_TURTLE_LONG;
		move_speed_delay = SPEED_DELAY_TURTLE_LONG;
		hit_box.w = TURTLE_LONG_WIDTH;
	}

	current_animation = 0;
	animatrion_status = 0;
	animation_status_max = TURTLE_ANIMATION_LENGTH;

	hit_box.h = TURTLE_HEIGHT;
	going_left = true;
	passed = 0;
	can_save_player = true;
}

int Turtle::load_sprite()
{
	Draw draw;
	if (turtle_type == TURTLE_SHORT)
	{
		if (dives == true)
		{
			if (draw.load_bmp(&sprite[0], PATH_TURTLE_SHORT_1) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[1], PATH_TURTLE_SHORT_DIVE_1) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[2], PATH_TURTLE_SHORT_DIVE_2) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[3], PATH_TURTLE_SHORT_DIVE_3) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[4], PATH_TURTLE_SHORT_DIVE_4) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[5], PATH_TURTLE_SHORT_DIVE_all) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[6], PATH_TURTLE_SHORT_DIVE_4) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[7], PATH_TURTLE_SHORT_DIVE_3) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[8], PATH_TURTLE_SHORT_DIVE_2) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[9], PATH_TURTLE_SHORT_DIVE_1) == LOADING_ERROR)
				return LOADING_ERROR;

			max_animation = TURTLE_SHORT_DIVE_ANIMATE_SRPITES_MAX_NUMBER;
		}
		else
		{
			if (draw.load_bmp(&sprite[0], PATH_TURTLE_SHORT_1) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[1], PATH_TURTLE_SHORT_2) == LOADING_ERROR)
				return LOADING_ERROR;

			max_animation = TURTLE_SHORT_NOT_DIVE_ANIMATE_SRPITES_MAX_NUMBER;

		}
		

	}
	else if (turtle_type == TURTLE_LONG)
	{
		if (dives == true)
		{
			if (draw.load_bmp(&sprite[0], PATH_TURTLE_LONG_1) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[1], PATH_TURTLE_LONG_DIVE_1) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[2], PATH_TURTLE_LONG_DIVE_2) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[3], PATH_TURTLE_LONG_DIVE_3) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[4], PATH_TURTLE_LONG_DIVE_4) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[5], PATH_TURTLE_LONG_DIVE_all) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[6], PATH_TURTLE_LONG_DIVE_4) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[7], PATH_TURTLE_LONG_DIVE_3) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[8], PATH_TURTLE_LONG_DIVE_2) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[9], PATH_TURTLE_LONG_DIVE_1) == LOADING_ERROR)
				return LOADING_ERROR;

			max_animation = TURTLE_LONG_DIVE_ANIMATE_SRPITES_MAX_NUMBER;
		}
		else
		{
			if (draw.load_bmp(&sprite[0], PATH_TURTLE_LONG_1) == LOADING_ERROR)
				return LOADING_ERROR;
			if (draw.load_bmp(&sprite[1], PATH_TURTLE_LONG_2) == LOADING_ERROR)
				return LOADING_ERROR;

			max_animation = TURTLE_LONG_NOT_DIVE_ANIMATE_SRPITES_MAX_NUMBER;
		}
	}
	

	actual_sprite = sprite[0];
	return LOADING_OK;
}

void Turtle::animate()
{
	can_save_player = false;

	if (animatrion_status >= animation_status_max)
	{
		animatrion_status = 0;
		current_animation++;
		if (current_animation >= max_animation)
			current_animation = 0;

		actual_sprite = sprite[current_animation];


		// if turtle dives then we want him to stay on the surface and under water a little bit longer
		if (dives == true && animation_status_max == TURTLE_ANIMATION_LENGTH && (actual_sprite == sprite[0] || actual_sprite == sprite[5]))
			animation_status_max *= 3;
		else
			animation_status_max = TURTLE_ANIMATION_LENGTH;
	}
	// if turtle dives then he can save player only when it is on the surface
	// if turtle doesn't dive then he can save player all the time
	if (dives == false || (dives == true && (actual_sprite == sprite[0] || actual_sprite == sprite[1])))
		can_save_player = true;
	animatrion_status++;
}

