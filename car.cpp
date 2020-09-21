#include "car.h"
#include "constants.h"
#include <cstdlib>

Car::~Car()
{
	for (int i = 0; i < max_animation; i++)
	{
		SDL_FreeSurface(sprite[i]);
	}
}

void Car::set_car_properties(int route_y)
{
	// Normal car
	if (route_y == CAR_ROUTE_1) 
	{
		car_type = CAR_1_LEFT;
		move_speed = SPEED_CAR_1_LEFT;
		move_speed_delay = SPEED_DELAY_CAR_1_LEFT;
		hit_box.w = CAR_1_WIDTH;
		max_animation = CAR_1_LEFT_ANIMATE_SRPITES_MAX_NUMBER;
		going_left = true;
	}
	// Normal car
	else if (route_y == CAR_ROUTE_2 )
	{
		car_type = CAR_1_RIGHT;
		move_speed = SPEED_CAR_1_RIGHT;
		move_speed_delay = SPEED_DELAY_CAR_1_RIGHT;
		hit_box.w = CAR_1_WIDTH;
		max_animation = CAR_1_RIGHT_ANIMATE_SRPITES_MAX_NUMBER;
		going_left = false;
	}
	// Truck
	else if (route_y == CAR_ROUTE_3)
	{
		car_type = CAR_2_RIGHT;
		move_speed = SPEED_CAR_2_RIGHT;
		move_speed_delay = SPEED_DELAY_CAR_2_RIGHT;
		hit_box.w = CAR_2_WIDTH;
		max_animation = CAR_2_RIGHT_ANIMATE_SRPITES_MAX_NUMBER;
		going_left = false;
	}
	// Truck
	else if (route_y == CAR_ROUTE_4)
	{
		car_type = CAR_2_LEFT;
		move_speed = SPEED_CAR_2_LEFT; 
		move_speed_delay = SPEED_DELAY_CAR_2_LEFT;
		hit_box.w = CAR_2_WIDTH;
		max_animation = CAR_2_LEFT_ANIMATE_SRPITES_MAX_NUMBER;
		going_left = true;
	}
	// Normall car
	else if (route_y == CAR_ROUTE_5)
	{
		car_type = CAR_1_LEFT;
		move_speed = SPEED_CAR_1_LEFT;
		move_speed_delay = SPEED_DELAY_CAR_1_LEFT;
		hit_box.w = CAR_1_WIDTH;
		max_animation = CAR_1_LEFT_ANIMATE_SRPITES_MAX_NUMBER;
		going_left = true;
	}

	current_animation = 0;
	animatrion_status = 0;
	animation_status_max = CAR_ANIMATION_LENGTH;

	hit_box.h = CAR_HEIGHT;
	passed = 0;
	can_save_player = false;
}

int Car::load_sprite()
{
	Draw draw; // LOADING CAR SPRITES CHANGING ACTUAL SPRITE DEPENDING ON ANIMATION STATUS czy w turtle.cpp potrzebny jest animation max?????!!!
	if (car_type == CAR_1_LEFT)
	{
		if (draw.load_bmp(&sprite[0], PATH_CAR_1_LEFT_1_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
		if (draw.load_bmp(&sprite[1], PATH_CAR_1_LEFT_2_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
		if (draw.load_bmp(&sprite[2], PATH_CAR_1_LEFT_3_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
		if (draw.load_bmp(&sprite[3], PATH_CAR_1_LEFT_4_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
		if (draw.load_bmp(&sprite[4], PATH_CAR_1_LEFT_5_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
		if (draw.load_bmp(&sprite[5], PATH_CAR_1_LEFT_6_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
	}
	else if (car_type == CAR_1_RIGHT)
	{
		if (draw.load_bmp(&sprite[0], PATH_CAR_1_RIGHT_1_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
		if (draw.load_bmp(&sprite[1], PATH_CAR_1_RIGHT_2_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
		if (draw.load_bmp(&sprite[2], PATH_CAR_1_RIGHT_3_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
		if (draw.load_bmp(&sprite[3], PATH_CAR_1_RIGHT_4_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
		if (draw.load_bmp(&sprite[4], PATH_CAR_1_RIGHT_5_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
		if (draw.load_bmp(&sprite[5], PATH_CAR_1_RIGHT_6_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
	}
	else if (car_type == CAR_2_LEFT)
	{
		if (draw.load_bmp(&sprite[0], PATH_CAR_2_LEFT_1_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
	}
	else if (car_type == CAR_2_RIGHT)
	{
		if (draw.load_bmp(&sprite[0], PATH_CAR_2_RIGHT_1_SPRITE) == LOADING_ERROR)
			return LOADING_ERROR;
	}
	actual_sprite = sprite[0];

	return LOADING_OK;
}

void Car::animate()
{
	// Object changes sprite after animation_status_max ticks has passed
	if (animatrion_status >= animation_status_max)
	{
		animatrion_status = 0;
		current_animation++;
		if (current_animation >= max_animation)
			current_animation = 0;
		actual_sprite = sprite[current_animation];
	}
	animatrion_status++;

}

void Car::collide(Player* player, World* world)
{
	if (check_collision_with_player(player) == true)
	{
		player->die();
		world->restart_game_time();
	}
}
