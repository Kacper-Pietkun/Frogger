#include "world.h"
#include "structures.h"
#include "constants.h"
#include "drawing.h"
#include "player.h"
#include <string.h>
#include <sstream>
#include <iostream>
#include <stdio.h>

using namespace std;


World::World(bool open_main_menu, bool is_paused, bool quit, double level_time)
{
	high_scores = HIGH_SCORES_CLOSED;
	main_menu = open_main_menu;
	pause = is_paused;
	quit_game = quit;
	time = level_time;
	writing_name = true;
}

World::~World()
{
	SDL_FreeSurface(sprite_pavement);
	SDL_FreeSurface(sprite_route);
	SDL_FreeSurface(sprite_water);
	SDL_FreeSurface(sprite_flowers);
	SDL_FreeSurface(sprite_player_lives);
	SDL_FreeSurface(sprite_pointer);
}

int World::load_sprites()
{
	Draw draw;
	if (draw.load_bmp(&sprite_pavement, PATH_PAVEMENT_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_route, PATH_ROUTE_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_water, PATH_WATER_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_flowers, PATH_FLOWERS_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_player_lives, PATH_PLAYER_UP_SPRITE) == LOADING_ERROR)
		return LOADING_ERROR;
	if (draw.load_bmp(&sprite_pointer, PATH_MENU_POINTER) == LOADING_ERROR)
		return LOADING_ERROR;

	return LOADING_OK;
}

void World::draw_world(Draw* draw, Player* player)
{
	position_t pos;
	
	// draw pavemnet_1
	pos.y = PAVEMENT_1_START_POS_Y;
	draw_one_line_world(draw, sprite_pavement, pos);
	
	// draw route
	pos.y = ROUTE_START_POS_Y;
	draw_more_line_world(draw, sprite_route, pos, FIVE_LINES);

	// draw pavemnet_2
	pos.y = PAVEMENT_2_START_POS_Y;
	draw_one_line_world(draw, sprite_pavement, pos);

	// draw water
	pos.y = WATER_START_POS_Y;
	draw_more_line_world(draw, sprite_water, pos, FIVE_LINES);

	// draw flowers
	pos.y = FLOWERS_START_POS_Y;
	draw_more_line_world(draw, sprite_flowers, pos, TWO_LINES);

	// draw player lives
	pos.y = PLAYER_LIVES_POS_Y;
	for (int i = 0; i < player->get_lives(); i++)
	{
		pos.x = WORLD_START_POS_X + i * DRAW_DELTA;
		draw->draw_surface(sprite_player_lives, pos);
	}
}

void World::draw_one_line_world(Draw* draw, struct SDL_Surface* sprite, position_t pos)
{
	for (int i = 0; i < 12; i++)
	{
		pos.x = WORLD_START_POS_X + i * DRAW_DELTA;
		draw->draw_surface(sprite, pos);
	}
}

void World::draw_more_line_world(Draw* draw, struct SDL_Surface* sprite, position_t pos, int lines)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			pos.x = WORLD_START_POS_X + j * DRAW_DELTA;
			draw->draw_surface(sprite, pos);
		}
		pos.y -= DRAW_DELTA;
	}
}

void World::game_paused(Draw* draw)
{
	if (pause == true)
	{
		draw_title_text_background(draw, " PAUSED ", TEXT_SIZE_20, -DRAW_DELTA/3);
		draw_text(draw, "PAUSED", TEXT_SIZE_20, NULL); // Drawing header of the game over menu
	}
}

void World::want_to_quit_game(Draw* draw)
{
	if (quit_game == true)
	{
		draw_title_text_background(draw, " QUIT GAME? Y/N " , TEXT_SIZE_20, -DRAW_DELTA / 3);
		draw_text(draw, "QUIT GAME? Y/N", TEXT_SIZE_20, NULL); // Drawing header of the game over menu
	}
}

void World::game_over(Player* player, Draw* draw, int option, char* nick_draw)
{
	if (player->get_game_over() == true)
	{
		if (writing_name == true)
		{
			// DRAW NICK THAT PLAYER TYPED
			draw_text(draw, nick_draw, TEXT_SIZE_20, -DRAW_DELTA);
			return;
		}
		

		position_t pointer_position;
		char* textes[GAME_OVER_MENU_CHOICES_NUMBER];
		textes[0] = "RESTART GAME";
		textes[1] = "MAIN MENU";
		textes[2] = "EXIT GAME";

		draw_text(draw, "GAME OVER", TEXT_SIZE_20, NULL); // Drawing header of the game over menu
		for (int i = 0; i < GAME_OVER_MENU_CHOICES_NUMBER; i++)
		{
			// Drawing pointer in menu
			// + 1 because here textes are counted from 0 and choices are counted from 1
			if (i + 1 == option)
			{
				pointer_position.x = SCREEN_WIDTH / 2 - strlen(textes[i]) / 2 * TEXT_SIZE_8 - POINTER_WIDTH;
				pointer_position.y = SCREEN_HEIGHT / 4 + DRAW_DELTA * (i + 2) / 2;
				draw->draw_surface(sprite_pointer, pointer_position);
			}
			draw_text(draw, textes[i], TEXT_SIZE_8, DRAW_DELTA * (i+2)/2);
		}
		// Sending DRAW_DELTA because these text must have different position.y
	}
}

void World::menu(Draw* draw, int option)
{
	if (main_menu == MAIN_MENU_OPENED)
	{
		position_t pointer_position;
		char* textes[MAIN_MENU_CHOICES_NUMBER];
		textes[0] = "NEW GAME";
		textes[1] = "HIGH SCORES";
		textes[2] = "EXIT GAME";

		draw_text(draw, "MAIN MENU", TEXT_SIZE_20, NULL); // Drawing header of the main menu
		for (int i = 0; i < MAIN_MENU_CHOICES_NUMBER; i++)
		{
			// Drawing pointer in menu
			// + 1 because here textes are counted from 0 and choices are counted from 1
			if (i + 1 == option)
			{
				pointer_position.x = SCREEN_WIDTH / 2 - strlen(textes[i]) / 2 * TEXT_SIZE_8 - POINTER_WIDTH;
				pointer_position.y = SCREEN_HEIGHT / 4 + DRAW_DELTA * (i + 2) / 2;
				draw->draw_surface(sprite_pointer, pointer_position);
			}
			draw_text(draw, textes[i], TEXT_SIZE_8, DRAW_DELTA * (i + 2) / 2);
		}
		// Sending DRAW_DELTA because these text must have different position.y
	}
}

void World::draw_scores(Draw* draw, Player* player)
{
	if (high_scores == HIGH_SCORES_OPENED)
	{
		// How many high scores there are
		char output[LETTERS_MAX_PLAYER_NICK * 2] = "";
		char scores_name[AMOUNT_OF_HIGH_SCORES][LETTERS_MAX_PLAYER_NICK];
		char scores_points[AMOUNT_OF_HIGH_SCORES][LETTERS_MAX_PLAYER_NICK];
		for (int i = 0; i < AMOUNT_OF_HIGH_SCORES; i++)
		{
			strcpy(scores_name[i], "EMPTY");
			strcpy(scores_points[i], "0");
		}
		FILE* file;
		file = fopen(PATH_HIGH_SCORES, "r");
		if (file != NULL)
		{
			for (int i = 0; i < AMOUNT_OF_HIGH_SCORES; i++)
			{
				if (fscanf(file, "%s %s\n", scores_name[i], scores_points[i]) <= 0)
					break;
			}
			fclose(file);
		}
		draw_text(draw, "HIGH SCORES", TEXT_SIZE_20, -DRAW_DELTA*1.5); // Drawing header of the main menu
		for (int i = 0; i < AMOUNT_OF_HIGH_SCORES; i++)
		{
			// concatenating char arrays
			stringstream buf;
			buf << i+1;
			string str = buf.str();
			strcpy(output, str.c_str());

			strcat(output, ". ");
			strcat(output, scores_name[i]);
			strcat(output, " ");
			strcat(output, scores_points[i]);

			draw_text(draw, output, TEXT_SIZE_8, DRAW_DELTA * (i + 2) / 2 - DRAW_DELTA * 1.8); // Drawing header of the main menu
		}
		
	}
}

void World::draw_text(Draw* draw, char* text, int size, int delta)
{
	// subtracting from position.x length of the text divided by two and multipled by size of the text because we want to text appear in the center of the game window
	position_t position;
	position.x = SCREEN_WIDTH / 2 - strlen(text) / 2 * size;
	position.y = SCREEN_HEIGHT / 4 + delta;
	draw->draw_string(position, text, size);
}

void World::draw_title_text_background(Draw* draw, char* text, int size, int delta)
{
	// subtracting from position.x length of the text divided by two and multipled by size of the text because we want to text appear in the center of the game window
	position_t position;
	position.x = SCREEN_WIDTH / 2 - strlen(text) / 2 * size;
	position.y = SCREEN_HEIGHT / 4 + delta;
	draw->draw_rectangle(position.x, position.y, strlen(text) * TEXT_SIZE_20, DRAW_DELTA, draw->get_color_red(), draw->get_color_black());
}

void World::draw_time_bar(Draw* draw, int color)
{
	// Sending this changing x position because draw rectangle function draws rectangle from left side so if x position was const then TIME BAR would decrease from right side and we want it to decrease from left side
	draw->draw_rectangle(TIME_BAR_POSITION_X + TIME_LEVEL * 4 - time * 4, TIME_BAR_POSITION_Y, time * 4, TIME_BAR_HEIGHT, color, color);
}

void World::draw_points(Draw* draw, Player* player)
{
	position_t position;
	position.x = POINTS_POSITION_X;
	position.y = POINTS_POSITION_Y;
	int points = player->get_point_manager_address()->get_points();
	char text[MAX_POINTS_TEXT];

	// Changing int to string and then to char array
	stringstream buf;
	buf << points;
	string str = buf.str();
	strcpy(text, str.c_str());

	draw->draw_string(position, "POINTS: ", TEXT_SIZE_20);
	position.x += 7 * TEXT_SIZE_20;
	draw->draw_string(position, text, TEXT_SIZE_20);
}

void World::restart_game(Player* player)
{
	player->restart();
	main_menu = false;
	restart_game_time();
	writing_name = true;
}

void World::update_time(double delta, Player* player)
{
	// here delta is the time in milliseconds since the last screen was drawn
	// delta * 0.001 is the same time in seconds
	time -= delta * 0.001;

	// Checks if player is out of time
	if (time <= 0)
	{
		player->die();
		restart_game_time();
	}
}

void World::restart_game_time()
{
	time = TIME_LEVEL;
}



void World::set_main_menu(bool status)
{
	main_menu = status;
}

bool World::get_main_menu()
{
	return main_menu;
}

void World::set_high_scores(bool status)
{
	high_scores = status;
}

bool World::get_high_scores()
{
	return high_scores;
}

void World::set_pause(bool status)
{
	pause = status;
}

bool World::get_pause()
{
	return pause;
}

void World::set_quit_game(bool status)
{
	quit_game = status;
}

bool World::get_quit_game()
{
	return quit_game;
}

void World::set_level_completed(bool status)
{
	level_completed = status;
}

bool World::get_level_completed()
{
	return level_completed;
}

bool World::get_writing_name()
{
	return writing_name;
}

void World::set_writing_name(bool status)
{
	writing_name = status;
}

double World::get_time()
{
	return time;
}
