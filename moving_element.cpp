#include "moving_element.h"
#include "constants.h"

int Moving_element::last_created_position_x = SCREEN_EDGE_LEFT;

void Moving_element::set_position(int pos_y, int draw_delta)
{
	// Setting position of the object and posotion of object's hit_box
	position.y = pos_y;
	hit_box.y = position.y - hit_box.h / 2;

	position.x = last_created_position_x;
	last_created_position_x += draw_delta;
	hit_box.x = position.x;// -hit_box.w / 2;
}

void Moving_element::move(Player* player)
{
	if (going_left == true)
	{
		move_direction(player, LEFT);
		loop_map_left();
	}
	else
	{
		move_direction(player, RIGHT);
		loop_map_right();
	}
	hit_box.x = position.x - hit_box.w / 2;
}

void Moving_element::move_direction(Player* player, int direction)
{
	if (passed == move_speed_delay)
	{
		position.x += move_speed * direction;
		passed = 0;
		// Check collision but this time move player
		if (player != NULL && check_collision_with_player(player) == true)
		{
			if(can_save_player == false)
				player->set_safe_on_water(false);
			else
			{
				player->moved_by_element(move_speed * direction);
				// Setting safe_on_water to true so water won't kill player
				player->set_safe_on_water(true);
			}
			
		}
	}
	// Check collision again don't move player because passed is not equal move_speed_delay and moving_object is not moving in this turn
	else if (player != NULL && check_collision_with_player(player) == true && can_save_player == true)
	{
		player->set_safe_on_water(true);
	}
	passed++;
}

void Moving_element::loop_map_left()
{
	if (position.x < SCREEN_EDGE_LEFT)
		position.x = SCREEN_EDGE_RIGHT;
}

void Moving_element::loop_map_right()
{
	if (position.x > SCREEN_EDGE_RIGHT)
		position.x = SCREEN_EDGE_LEFT;
}

void Moving_element::reset_last_created_pos_x()
{
	last_created_position_x = SCREEN_EDGE_LEFT;
}

bool Moving_element::check_collision_with_player(Player* player)
{
	if (SDL_HasIntersection(&hit_box, player->get_hit_box_address()) == SDL_TRUE)
		return true;
	else
		return false;
}