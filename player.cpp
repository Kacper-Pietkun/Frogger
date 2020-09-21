#include "player.h"
#include "constants.h"
#include "structures.h"
#include "drawing.h"
#include <stdio.h>


Player::Player(position_t pos, int hearths, int d_move, int width, int height)
{
	position.x = pos.x;
	position.y = pos.y;
	lives = hearths;
	delta_move = d_move;
	hit_box.w = width;
	hit_box.h = height;
	hit_box.x = position.x - hit_box.w / 2;
	hit_box.y = position.y - hit_box.h / 2;
	safe_on_water = false;
	game_over = false;
	actual_position = 0;
	nearest_position = 0;
	actual_sprite = NULL;
	direction = NO_MOVEMENT;
	animation_max = ANIMATION_LENGTH;
	animation_status = 0;
}

Player::~Player()
{
	SDL_FreeSurface(sprite_up);
	SDL_FreeSurface(sprite_up_move);
	SDL_FreeSurface(sprite_down);
	SDL_FreeSurface(sprite_down_move);
	SDL_FreeSurface(sprite_right);
	SDL_FreeSurface(sprite_right_move);
	SDL_FreeSurface(sprite_left);
	SDL_FreeSurface(sprite_left_move);
}

int Player::load_sprites()
{
	Draw draw;
	if (draw.load_bmp(&sprite_up, PATH_PLAYER_UP_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_up_move, PATH_PLAYER_UP_MOVE_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_down, PATH_PLAYER_DOWN_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_down_move, PATH_PLAYER_DOWN_MOVE_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_right, PATH_PLAYER_RIGHT_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_right_move, PATH_PLAYER_RIGHT_MOVE_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_left, PATH_PLAYER_LEFT_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_left_move, PATH_PLAYER_LEFT_MOVE_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;

	actual_sprite = sprite_up;

	return LOADING_OK;
}

void Player::move_vertical(bool up)
{
	// checking if player moves up or down and he moves only if he won't jump out of the map
	if (up == true && animation_status < animation_max)
	{
		if(!(position.y - delta_move >= MAX_POS_UP))
			animation_status = animation_max;
		else
		{
			actual_sprite = sprite_up;
			position.y -= delta_move;
			if (animation_status > 1 && animation_status < animation_max - 1)
				actual_sprite = sprite_up_move;
			else
				actual_sprite = sprite_up;
		}
		
	}
	else if (up == false && animation_status < animation_max)
	{
		if (!(position.y + delta_move <= MAX_POS_DOWN))
			animation_status = animation_max;
		else
		{
			actual_sprite = sprite_down;
			position.y += delta_move;
			if (animation_status > 1 && animation_status < animation_max - 1)
				actual_sprite = sprite_down_move;
			else
				actual_sprite = sprite_down;
		}
		
	}

	animation_status++;

	if (animation_status >= animation_max)
	{
		// Change players position for points only after animation is over
		if(up == true)
			actual_position++;
		else
			actual_position--;
		direction = NO_MOVEMENT;
		animation_status = 0;
	}

	hit_box.y = position.y - hit_box.h / 2; // updating only hit_box.y because players moved vertically
	safe_on_water = false; // everytime player moves it becomes unsafe on water and he will die if he doesn't jump on either turtle or tree trunk
}

void Player::move_horizontal(bool left)
{
	// checking if player moves left or right
	// if player is on the route then he can't go outside of the map using input arrows, however if he is on the water he can do it (of course he will lose his live)
	if (left == true && animation_status < animation_max)
	{
		// if player cannot go further in the map
		if (!(position.x - delta_move >= MAX_POS_LEFT || position.y <= WATER_START_POS_Y))
			animation_status = animation_max;
		else
		{
			actual_sprite = sprite_left;
			position.x -= delta_move;
			if (animation_status > 1 && animation_status < animation_max - 1)
				actual_sprite = sprite_left_move;
			else
				actual_sprite = sprite_left;
		}
		
	}
	else if (left == false && animation_status < animation_max)
	{
		// if player cannot go further in the map
		if (!(position.x + delta_move <= MAX_POS_RIGHT || position.y <= WATER_START_POS_Y))
			animation_status = animation_max;
		else
		{
			actual_sprite = sprite_right;
			position.x += delta_move;
			if (animation_status > 1 && animation_status < animation_max - 1)
				actual_sprite = sprite_right_move;
			else
				actual_sprite = sprite_right;
		}
	}
	animation_status++;

	if (animation_status >= animation_max)
	{
		direction = NO_MOVEMENT;
		animation_status = 0;
	}

	hit_box.x = position.x - hit_box.w / 2;// updating only hit_box.x because players moved horizontally 
	safe_on_water = false; // everytime player moves it becomes unsafe on water and he will die if he doesn't jump on either turtle or tree trunks
}

void Player::moved_by_element(int delta)
{
	position.x += delta;
	hit_box.x = position.x - hit_box.w / 2;
}

void Player::die()
{
	if (lives > 1)
	{
		position.x = PLAYER_START_POS_X;
		position.y = PLAYER_START_POS_Y;
		hit_box.x = position.x - hit_box.w / 2;
		hit_box.y = position.y - hit_box.h / 2;
		lives--;
		nearest_position = 0;
		actual_position = 0;
		actual_sprite = sprite_up;
		direction = NO_MOVEMENT;
		animation_status = 0;
	}
	// if player lost all of his lives
	else
	{
		lives = 0;
		// Setting this bool on  true will open game over menu by World class
		game_over = true;
	}
}

void Player::collide_with_water(class World* world)
{
	// if player jump into the water || If player is out of map on the water
	if ((safe_on_water == false && position.y <= WATER_START_POS_Y) || (position.y <= WATER_START_POS_Y && (position.x <= PLAYER_MAX_LEFT_WATER || position.x >= PLAYER_MAX_RIGHT_WATER)))
	{
		die();
		world->restart_game_time();
	}
}

void Player::spot_completed()
{
	actual_sprite = sprite_up;
	position.x = PLAYER_START_POS_X;
	position.y = PLAYER_START_POS_Y;
	hit_box.x = position.x - hit_box.w / 2;
	hit_box.y = position.y - hit_box.h / 2;
	direction = NO_MOVEMENT;
	animation_status = 0;
}

void Player::restart()
{
	spot_completed();
	game_over = false;
	nearest_position = 0;
	actual_position = 0;
	point_manager.set_points(0);
	lives = PLAYER_LIVES;
	direction = NO_MOVEMENT;
	animation_status = 0;
}

void Player::animate()
{
	switch (direction)
	{
	case UP_DIR:
		move_vertical(PLAYER_MOVE_UP);
		break;
	case DOWN_DIR:
		move_vertical(PLAYER_MOVE_DOWN);
		break;
	case RIGHT_DIR:
		move_horizontal(PLAYER_MOVE_RIGHT);
		break;
	case LEFT_DIR:
		move_horizontal(PLAYER_MOVE_LEFT);
		break;
	}
}

void Player::check_points_position()
{
	if (actual_position > nearest_position)
	{
		point_manager.add_points(POINTS_ADDED_CLOSER);
		nearest_position = actual_position;
	}
}

void Player::set_safe_on_water(bool safe)
{
	safe_on_water = safe;
}

void Player::set_pos_x(int pos)
{
	position.x = pos;
}

void Player::set_pos_y(int pos)
{
	position.y = pos;
}

bool Player::get_safe_on_water()
{
	return safe_on_water;
}

int Player::get_pos_x()
{
	return position.x;
}

int Player::get_lives()
{
	return lives;
}

bool Player::get_game_over()
{
	return game_over;
}

void Player::set_game_over(bool status)
{
	game_over = status;
}

void Player::set_lives(int number_of_lives)
{
	lives = number_of_lives;
}

direction_t Player::get_direction()
{
	return direction;
}

void Player::set_direction(direction_t dir)
{
	direction = dir;
}

Point_manager* Player::get_point_manager_address()
{
	return &point_manager;
}


