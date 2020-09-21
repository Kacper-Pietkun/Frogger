#ifndef world_h
#define world_h

#include "structures.h"
#include "drawing.h"
#include "player.h"


// declare class so player can use world
class Player;

class World
{
private:
	struct SDL_Surface* sprite_pavement;
	struct SDL_Surface* sprite_route;
	struct SDL_Surface* sprite_water;
	struct SDL_Surface* sprite_flowers;
	struct SDL_Surface* sprite_player_lives;
	struct SDL_Surface* sprite_pointer;

	bool writing_name;

	bool level_completed;
	bool main_menu;
	bool high_scores;
	bool pause;
	bool quit_game;
	double time;

public:
	World(bool open_main_menu, bool is_paused, bool quit, double level_time);
	~World();

	// Loading all sprites which appear in the background
	int load_sprites();

	// DRAWING BACKGROUND
	// *************************************************
	void draw_world(Draw* draw, Player* player);
	// for example one line of pavement
	void draw_one_line_world(Draw* draw, struct SDL_Surface* sprite, position_t pos);
	// for example five lines of rout or the water
	void draw_more_line_world(Draw* draw, struct SDL_Surface* sprite, position_t pos, int lines);
	// *************************************************

	// Draws information if game is paused
	void game_paused(Draw* draw);
	// Draws question if player wants to quit the game
	void want_to_quit_game(Draw* draw);
	// Draws game over menu, player can choose to restart game or go to the main menu or exit game
	void game_over(Player* player, Draw* draw, int option, char* nick_draw);
	// Draws main menu, player can choose to start new game or exit game
	void menu(Draw* draw, int option);
	// Draws high scores, player can choose to go back to main menu
	void draw_scores(Draw* draw, Player* player);

	// Drawing text in different menus
	void draw_text(Draw* draw, char* text, int size, int delta);
	void draw_title_text_background(Draw* draw, char* text, int size, int delta);

	void restart_game(Player* player);

	void draw_time_bar(Draw* draw, int color);

	void draw_points(Draw* draw, Player* player);

	// Decreasing level time
	void update_time(double delta, Player* player);

	// Level time is restared when players dies or complete one of the ending spots or the game is restarted
	void restart_game_time();

	// GETTING AND SETTING VARIABLES
	// *************************************************
	void set_main_menu(bool status);
	bool get_main_menu();

	void set_high_scores(bool status);
	bool get_high_scores();

	void set_pause(bool status);
	bool get_pause();

	void set_quit_game(bool status);
	bool get_quit_game();

	bool get_level_completed();
	void set_level_completed(bool status);

	bool get_writing_name();
	void set_writing_name(bool status);

	double get_time();
	// *************************************************

};

#endif // world_h
