#include "tree_trunk.h"
#include "constants.h"

Tree_trunk::~Tree_trunk()
{
	SDL_FreeSurface(actual_sprite);
}

void Tree_trunk::set_tree_type(int type)
{
	tree_type = type;
	if (type == TREE_SHORT)
	{
		sprite_path = PATH_TREE_TRUNK_SHORT;
		move_speed = SPEED_TREE_SHORT;
		move_speed_delay = SPEED_DELAY_TREE_SHORT;
		hit_box.w = TREE_SHORT_WIDTH;
	}
	else if (type == TREE_MIDDLE)
	{
		sprite_path = PATH_TREE_TRUNK_MIDDLE;
		move_speed = SPEED_TREE_MIDDLE;
		move_speed_delay = SPEED_DELAY_TREE_MIDDLE;
		hit_box.w = TREE_MIDDLE_WIDTH;
	}
	else if (type == TREE_LONG)
	{
		sprite_path = PATH_TREE_TRUNK_LONG;
		move_speed = SPEED_TREE_LONG;
		move_speed_delay = SPEED_DELAY_TREE_LONG;
		hit_box.w = TREE_LONG_WIDTH;
	}
	hit_box.h = TREE_HEIGHT;
	going_left = false;
	passed = 0;
	can_save_player = true;
}

int Tree_trunk::load_sprite()
{
	Draw draw;
	if (draw.load_bmp(&actual_sprite, sprite_path) == LOADING_ERROR)
		return LOADING_ERROR;


	return LOADING_OK;
}


