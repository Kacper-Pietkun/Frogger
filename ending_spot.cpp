#include "ending_spot.h"
#include "constants.h"
#include "structures.h"

int Ending_spot::spots_completed = 0;
bool Ending_spot::level_done = false;

Ending_spot::~Ending_spot()
{
	SDL_FreeSurface(sprite_lily);
	SDL_FreeSurface(sprite_lily_busy);
}

void Ending_spot::set_properties(char* sprite, char* sprite_busy, position_t pos)
{
	actual_sprite = NULL;
	sprite_lily = NULL;
	sprite_lily_busy = NULL;

	sprite_lily_path = sprite;
	sprite_lily_busy_path = sprite_busy;

	position.x = pos.x;
	position.y = pos.y;
	busy = false;
	hit_box.w = ENDING_SPOT_WIDTH;
	hit_box.h = ENDING_SPOT_HEIGHT;
	hit_box.x = position.x - hit_box.w / 2; // position.x is the center of the sprite and hit_box.x must by cooridantes of upper left corner
	hit_box.y = position.y - hit_box.h / 2;
}

int Ending_spot::load_sprite()
{
	Draw draw;
	if (draw.load_bmp(&sprite_lily, sprite_lily_path) == LOADING_ERROR)
		return LOADING_ERROR;

	if (draw.load_bmp(&sprite_lily_busy, sprite_lily_busy_path) == LOADING_ERROR)
		return LOADING_ERROR;

	actual_sprite = sprite_lily;
	return LOADING_OK;
}

void Ending_spot::draw_spot(Draw* draw)
{
	draw->draw_surface(actual_sprite, position);
}

void Ending_spot::player_jumped(Player* player, World* world, Ending_spot spots[])
{
	if (check_collision_with_player(player) == true)
	{
		// checking if spot is already taken
		if (busy == false)
		{
			actual_sprite = sprite_lily_busy;
			busy = true;
			spots_completed++;

			int points_to_add = POINTS_SPOT_COMPLETED + POINTS_TIME_MULTIPLIER * world->get_time();
			player->get_point_manager_address()->add_points(points_to_add);

			player->set_safe_on_water(true);
			player->spot_completed(); // Makes player appear on the starting positio, updates his hitboxes
			world->restart_game_time();

			if (spots_completed == ENDING_SPOTS_NUMBER)
				level_completed(player, world, spots, ENDING_SPOTS_NUMBER);
			
		}
		else
		{
			// It means that player will die
			player->set_safe_on_water(false);
		}
	}
}

void Ending_spot::level_completed(Player* player, World* world, Ending_spot spots[], int spots_number)
{
	player->spot_completed();// Makes player appear on the starting positio, updates his hitboxes
	world->restart_game_time();
	for (int i = 0; i < spots_number; i++)
	{
		spots[i].set_busy(false);
		spots[i].change_sprite();
	}
	spots_completed = 0;
	level_done = true;
}

void Ending_spot::change_sprite()
{
	if (busy == false)
		actual_sprite = sprite_lily;
	else
		actual_sprite = sprite_lily_busy;
}

bool Ending_spot::check_collision_with_player(Player* player)
{
	if (SDL_HasIntersection(&hit_box, player->get_hit_box_address()) == SDL_TRUE)
		return true;
	else
		return false;
}

void Ending_spot::set_busy(bool status)
{
	busy = status;

	// Updatin lily sprite accordin to busy variable
	if (busy == true)
		actual_sprite = sprite_lily_busy;
	else
		actual_sprite = sprite_lily;
}

SDL_Surface* Ending_spot::get_sprite_lily()
{
	return sprite_lily;
}

SDL_Surface* Ending_spot::get_sprite_lily_busy()
{
	return sprite_lily_busy;
}