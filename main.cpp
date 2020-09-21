#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
extern "C"
{
#include "SDL2-2.0.10/include/SDL.h"
#include "SDL2-2.0.10/include/SDL_main.h"
}

#include "drawing.h"
#include "structures.h"
#include "constants.h"
#include "player.h"
#include "world.h"
#include "car.h"
#include "tree_trunk.h"
#include "turtle.h"
#include "ending_spot.h"

using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));
	int quit;
	int rc;
	int t1, t2, level_done_t1, level_done_t2;
	int game_over_menu_option, main_menu_option;
	char player_name_draw[LETTERS_MAX_PLAYER_NICK] = "ENTER YOUR NAME: "; // This will be drawn on the screen
	char player_name[LETTERS_MAX_PLAYER_NICK] = ""; // actual name
	string name;

	SDL_Event event;

	Draw draw;
	
	// CREATING WORLD (BACKGROUND OF THE GAME)
	// *******************************************************
	World world(MAIN_MENU_OPENED, GAME_NOT_PAUSED, QUIT_CLOSED, TIME_LEVEL);
	if (world.load_sprites() == LOADING_ERROR)
		return EXIT_PROGRAM_WITH_ERROR;
	// *******************************************************



	// CREATING ENDING SPOT (DESTINATION OF FROG (player))
	// *******************************************************
	Ending_spot ending_spots[ENDING_SPOT_NUMBER];
	position_t position;
	position.y = ENDING_SPOT_POS_Y;
	for (int i = 0; i < ENDING_SPOT_NUMBER; i++)
	{
		position.x = ENDING_SPOT_1_POS_X + 2*i * DRAW_DELTA;
		ending_spots[i].set_properties(PATH_LILY_SPRITE, PATH_LILY_BUSY_SPRITE, position);

		if (ending_spots[i].load_sprite() == LOADING_ERROR)
			return EXIT_PROGRAM_WITH_ERROR;
	}
	// *******************************************************



	// CREATING PLAYER
	// *******************************************************
	position_t player_pos;
	player_pos.x = PLAYER_START_POS_X;
	player_pos.y = PLAYER_START_POS_Y;
	Player player(player_pos, PLAYER_0_LIVES, PLAYER_JUMP, PLAYER_WIDTH, PLAYER_HEIGHT);
	if (player.load_sprites() == LOADING_ERROR)
		return EXIT_PROGRAM_WITH_ERROR;
	// *******************************************************
	
	
	
	// CREATING CARS
	// *******************************************************
	Car car[CAR_NUMBER];
	for (int i = 0; i < CAR_NUMBER; i++)
	{
		// Creating different model of cars by turn 
		// EACH NUMBER DESCRIBES THE ROUTE
		switch (i % 5 + 1)
		{
		case 1:
			car[i].set_car_properties(CAR_ROUTE_1);
			car[i].set_position(CAR_ROUTE_1, CAR_ROUTE_1_DRAW_DELTA);
			break;
		case 2:
			car[i].set_car_properties(CAR_ROUTE_2);
			car[i].set_position(CAR_ROUTE_2, CAR_ROUTE_2_DRAW_DELTA);
			break;
		case 3:
			car[i].set_car_properties(CAR_ROUTE_3);
			car[i].set_position(CAR_ROUTE_3, CAR_ROUTE_3_DRAW_DELTA);
			break;
		case 4:
			car[i].set_car_properties(CAR_ROUTE_4);
			car[i].set_position(CAR_ROUTE_4, CAR_ROUTE_4_DRAW_DELTA);
			break;
		case 5:
			car[i].set_car_properties(CAR_ROUTE_5);
			car[i].set_position(CAR_ROUTE_5, CAR_ROUTE_5_DRAW_DELTA);
			break;

		}

		if (car[i].load_sprite() == LOADING_ERROR)
			return EXIT_PROGRAM_WITH_ERROR;

	}
	// *******************************************************



	// CREATING TREES
	// *******************************************************
	Tree_trunk tree_short[TREE_SHORT_NUMBER];
	Tree_trunk tree_middle[TREE_MIDDLE_NUMBER];
	Tree_trunk tree_long[TREE_LONG_NUMBER];

	tree_short[0].reset_last_created_pos_x();
	for (int i = 0; i < TREE_SHORT_NUMBER; i++)
	{
		tree_short[i].set_tree_type(TREE_SHORT);

		if (tree_short[i].load_sprite() == LOADING_ERROR)
			return EXIT_PROGRAM_WITH_ERROR;

		tree_short[i].set_position(SHORT_TREE_ROUTE, DRAW_DELTA_SHORT_TREE);
	}
	tree_middle[0].reset_last_created_pos_x();
	for (int i = 0; i < TREE_MIDDLE_NUMBER; i++)
	{
		tree_middle[i].set_tree_type(TREE_MIDDLE);

		if (tree_middle[i].load_sprite() == LOADING_ERROR)
			return EXIT_PROGRAM_WITH_ERROR;

		tree_middle[i].set_position(MIDDLE_TREE_ROUTE, DRAW_DELTA_MIDDLE_TREE);
	}
	tree_long[0].reset_last_created_pos_x();
	for (int i = 0; i < TREE_LONG_NUMBER; i++)
	{
		tree_long[i].set_tree_type(TREE_LONG);

		if (tree_long[i].load_sprite() == LOADING_ERROR)
			return EXIT_PROGRAM_WITH_ERROR;

		tree_long[i].set_position(LONG_TREE_ROUTE, DRAW_DELTA_LONG_TREE);
	}
	// *******************************************************



	// CREATING TURTLES
	// *******************************************************
	Turtle turtle_short[NUMBER_SHORT_TURTLE];
	Turtle turtle_long[NUMBER_LONG_TURTLE];

	turtle_short[0].reset_last_created_pos_x();
	for (int i = 0; i < NUMBER_SHORT_TURTLE; i++)
	{
		// every other turtle dives
		if (i % 2 == 0)
			turtle_short[i].set_turtle_type(TURTLE_SHORT, DIVE);
		else
			turtle_short[i].set_turtle_type(TURTLE_SHORT, NOT_DIVE);


		if (turtle_short[i].load_sprite() == LOADING_ERROR)
			return EXIT_PROGRAM_WITH_ERROR;

		turtle_short[i].set_position(TURTLE_SHORT_ROUTE, DRAW_DELTA_SHORT_TURTLE);
	}
	turtle_long[0].reset_last_created_pos_x();
	for (int i = 0; i < NUMBER_LONG_TURTLE; i++)
	{
		// every other turtle dives
		if (i % 2 == 0)
			turtle_long[i].set_turtle_type(TURTLE_LONG, DIVE);
		else
			turtle_long[i].set_turtle_type(TURTLE_LONG, NOT_DIVE);

		
		if (turtle_long[i].load_sprite() == LOADING_ERROR)
			return EXIT_PROGRAM_WITH_ERROR;

		turtle_long[i].set_position(TURTLE_LONG_ROUTE, DRAW_DELTA_LONG_TURTLE);
	}
	
	// *******************************************************



	// This loop makes cars ride so when player enter the game there is some traffic on the route
	// Sending NULL as a parameter beacuse every object moves without Player sitting on it
	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < CAR_NUMBER; j++)
			car[j].move(NULL);

		for (int j = 0; j < TREE_SHORT_NUMBER; j++)
			tree_short[j].move(NULL);
		for (int j = 0; j < TREE_MIDDLE_NUMBER; j++)
			tree_middle[j].move(NULL);
		for (int j = 0; j < TREE_LONG_NUMBER; j++)
			tree_long[j].move(NULL);

		for (int j = 0; j < NUMBER_SHORT_TURTLE; j++)
			turtle_short[j].move(NULL);
		for (int j = 0; j < NUMBER_LONG_TURTLE; j++)
			turtle_long[j].move(NULL);
	}



	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL_Init error: %s\n", SDL_GetError());
		return 1;
	}

	// fullscreen mode
	// rc = SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, draw.get_window_address(), draw.get_renderer_address());

	rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, draw.get_window_address(), draw.get_renderer_address());
	if (rc != 0)
	{
		SDL_Quit();
		printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		return 1;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(draw.get_renderer(), SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(draw.get_renderer(), 0, 0, 0, 255);

	SDL_SetWindowTitle(draw.get_window(), "Frogger");

	draw.set_screen(SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000));
	draw.set_scrtex(SDL_CreateTexture(draw.get_renderer(), SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT));

	// hide cursor
	SDL_ShowCursor(SDL_DISABLE);


	// loading charsets
	if(draw.load_bmp(draw.get_charset_8x8_address(), PATH_CHARSET_8x8) == LOADING_ERROR)
		return EXIT_PROGRAM_WITH_ERROR;
	if (draw.load_bmp(draw.get_charset_20x20_address(), PATH_CHARSET_20x20) == LOADING_ERROR)
		return EXIT_PROGRAM_WITH_ERROR;

	SDL_SetColorKey(draw.get_charset_8x8(), true, 0x000000);
	SDL_SetColorKey(draw.get_charset_20x20(), true, 0x000000);

	draw.set_color_black(SDL_MapRGB(draw.get_screen()->format, 0x00, 0x00, 0x00));
	draw.set_color_green(SDL_MapRGB(draw.get_screen()->format, 0x00, 0xFF, 0x00));
	draw.set_color_red(SDL_MapRGB(draw.get_screen()->format, 0xFF, 0x00, 0x00));
	draw.set_color_blue(SDL_MapRGB(draw.get_screen()->format, 0x11, 0x11, 0xCC));


	t1 = SDL_GetTicks();
	quit = DONT_EXIT_PROGRAM;
	game_over_menu_option = 1;
	main_menu_option = 1;


	while (quit != EXIT_PROGRAM)
	{
		t2 = SDL_GetTicks();

		SDL_FillRect(draw.get_screen(), NULL, draw.get_color_black());

		// drawing objects
		world.draw_world(&draw, &player);
		for (int i = 0; i < ENDING_SPOT_NUMBER; i++)
		{
			// If player lost all of his lives then print ending spots as they are not busy
			if(player.get_game_over() == true || world.get_main_menu() == MAIN_MENU_OPENED)
				ending_spots[i].set_busy(false);
			ending_spots[i].draw_spot(&draw);
			ending_spots[i].player_jumped(&player, &world, ending_spots);
		}

		// Draw it only if player didn't lose all of his lives and all menus are closed
		if (player.get_game_over() == false && world.get_main_menu() == MAIN_MENU_CLOSED && world.get_high_scores() == HIGH_SCORES_CLOSED)
		{
			for (int i = 0; i < CAR_NUMBER; i++)
			{
				car[i].draw_sprite(&draw);
				if (world.get_pause() == GAME_NOT_PAUSED && world.get_quit_game() == QUIT_CLOSED)
				{
					car[i].animate();
					car[i].move(NULL);
					car[i].collide(&player, &world);
				}
			}
			for (int i = 0; i < TREE_SHORT_NUMBER; i++)
			{
				tree_short[i].draw_sprite(&draw);
				if (world.get_pause() == GAME_NOT_PAUSED && world.get_quit_game() == QUIT_CLOSED)
					tree_short[i].move(&player);
			}
			for (int i = 0; i < TREE_MIDDLE_NUMBER; i++)
			{
				tree_middle[i].draw_sprite(&draw);
				if (world.get_pause() == GAME_NOT_PAUSED && world.get_quit_game() == QUIT_CLOSED)
					tree_middle[i].move(&player);
			}
			for (int i = 0; i < TREE_LONG_NUMBER; i++)
			{
				tree_long[i].draw_sprite(&draw);
				if (world.get_pause() == GAME_NOT_PAUSED && world.get_quit_game() == QUIT_CLOSED)
					tree_long[i].move(&player);
			}
			for (int i = 0; i < NUMBER_SHORT_TURTLE; i++)
			{
				turtle_short[i].draw_sprite(&draw);
				if (world.get_pause() == GAME_NOT_PAUSED && world.get_quit_game() == QUIT_CLOSED)
				{
					turtle_short[i].animate();
					turtle_short[i].move(&player);
				}
			}
			for (int i = 0; i < NUMBER_LONG_TURTLE; i++)
			{
				turtle_long[i].draw_sprite(&draw);
				if (world.get_pause() == GAME_NOT_PAUSED && world.get_quit_game() == QUIT_CLOSED)
				{
					turtle_long[i].animate();
					turtle_long[i].move(&player);
				}
			}
			player.collide_with_water(&world);
			player.check_points_position(); // Checking it here because we need to know if player has survived on a new spot
			if (player.get_direction() != NO_MOVEMENT)
				player.animate();
			player.draw_sprite(&draw);

			

			world.draw_points(&draw, &player);

			// UPDATE TIME
			if (world.get_pause() == GAME_NOT_PAUSED && world.get_quit_game() == QUIT_CLOSED)
			{
				world.update_time(t2 - t1, &player);
			}
			if(world.get_time() <= TIME_RED_LEVEL)
				world.draw_time_bar(&draw, draw.get_color_red());
			else
				world.draw_time_bar(&draw, draw.get_color_green());

			if (Ending_spot::level_done == true)
			{
				level_done_t1 = SDL_GetTicks();
				Ending_spot::level_done = false;
				world.set_level_completed(true);
			}

			if (world.get_level_completed() == true)
			{
				world.draw_title_text_background(&draw, " LEVEL COMPLETED ", TEXT_SIZE_20, -DRAW_DELTA / 3);
				world.draw_text(&draw, "LEVEL COMPLETED", TEXT_SIZE_20, NULL);
				level_done_t2 = SDL_GetTicks();
				// here level_done_t2 - level_done_t1 is the time in milliseconds since the last screen was drawn
				// level_done_t2 - level_done_t1 * 0.001 is the same time in seconds
				if ((level_done_t2 - level_done_t1) * 0.001 >= DRAW_LEVEL_COMPLETED_TIME)
					world.set_level_completed(false);
			}

		}
		t1 = t2;
		
		// Check if player clicked q (want to quit game)
		world.want_to_quit_game(&draw);

		// Check if player is in main menu
		world.menu(&draw, main_menu_option);

		world.draw_scores(&draw, &player);
		
		// Check if player lost all of his lives
		world.game_over(&player, &draw, game_over_menu_option, player_name_draw);

		// Check if game is paused
		world.game_paused(&draw);

		SDL_UpdateTexture(draw.get_scrtex(), NULL, draw.get_screen()->pixels, draw.get_screen()->pitch);
		//		SDL_RenderClear(renderer);
		SDL_RenderCopy(draw.get_renderer(), draw.get_scrtex(), NULL, NULL);
		SDL_RenderPresent(draw.get_renderer());

		// handling of events (if there were any)
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = EXIT_PROGRAM;
				}
				else if (event.key.keysym.sym == SDLK_UP)
				{
					if (player.get_game_over() == true && game_over_menu_option > 1)
					{
						game_over_menu_option--;
					}
					else if (world.get_main_menu() == true && main_menu_option > 1)
					{
						main_menu_option--;
					}
					else if (world.get_pause() == GAME_NOT_PAUSED && world.get_quit_game() == QUIT_CLOSED && player.get_direction() == NO_MOVEMENT)
					{
						player.set_direction(UP_DIR);
					}
				}
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					if (player.get_game_over() == MAIN_MENU_OPENED && game_over_menu_option < GAME_OVER_MENU_CHOICES_NUMBER)
					{
						game_over_menu_option++;
					}
					else if (world.get_main_menu() == MAIN_MENU_OPENED && main_menu_option < MAIN_MENU_CHOICES_NUMBER)
					{
						main_menu_option++;
					}
					else if (world.get_pause() == GAME_NOT_PAUSED && world.get_quit_game() == QUIT_CLOSED && player.get_direction() == NO_MOVEMENT)
					{
						player.set_direction(DOWN_DIR);
					}
				}
				else if (event.key.keysym.sym == SDLK_LEFT && world.get_pause() == GAME_NOT_PAUSED && world.get_quit_game() == QUIT_CLOSED && player.get_direction() == NO_MOVEMENT)
				{
					player.set_direction(LEFT_DIR);
				}
				else if (event.key.keysym.sym == SDLK_RIGHT && world.get_pause() == GAME_NOT_PAUSED && world.get_quit_game() == QUIT_CLOSED && player.get_direction() == NO_MOVEMENT)
				{
					player.set_direction(RIGHT_DIR);
				}
				else if (event.key.keysym.sym == SDLK_RETURN)
				{
					// if player clicks enter in game over menu
					if (player.get_game_over() == true)
					{
						// When player entered his name then menu should appear thats why we change writing name to false
						// Also before menu appear we save score to file
						if (world.get_writing_name() == true)
						{
							player.get_point_manager_address()->get_high_scores();
							player.get_point_manager_address()->save_score(player_name);
							world.set_writing_name(false);
							name = "";
							strcpy(player_name_draw, "ENTER YOUR NAME: ");
							strcpy(player_name, "");
						}
						else
						{
							switch (game_over_menu_option)
							{
							case 1:
								world.restart_game(&player);
								Ending_spot::spots_completed = 0;
								Ending_spot::level_done = false;
								game_over_menu_option = 1;
								break;
							case 2:
								player.set_game_over(false);
								world.set_main_menu(MAIN_MENU_OPENED);
								game_over_menu_option = 1;
								break;
							case 3:
								quit = EXIT_PROGRAM;
								break;
							}
						}
					}
					// if player clicks enter in main menu
					else if (world.get_main_menu() == MAIN_MENU_OPENED)
					{
						switch (main_menu_option)
						{
						case 1:
							world.restart_game(&player);
							Ending_spot::spots_completed = 0;
							Ending_spot::level_done = false;
							main_menu_option = 1;
							break;
						case 2:
							world.set_high_scores(HIGH_SCORES_OPENED);
							world.set_main_menu(MAIN_MENU_CLOSED);
							break;
						case 3:
							quit = EXIT_PROGRAM;
							break;
						}
					}
					else if (world.get_high_scores() == HIGH_SCORES_OPENED)
					{
						world.set_high_scores(HIGH_SCORES_CLOSED);
						world.set_main_menu(MAIN_MENU_OPENED);
					}
				}
				else if (event.key.keysym.sym == SDLK_p)
				{
					if (world.get_main_menu() == MAIN_MENU_CLOSED && player.get_game_over() == false && world.get_quit_game() == QUIT_CLOSED)
					{
						if (world.get_pause() == GAME_PAUSED)
							world.set_pause(GAME_NOT_PAUSED);
						else
							world.set_pause(GAME_PAUSED);
					}
				}
				else if (event.key.keysym.sym == SDLK_q)
				{
					if (world.get_main_menu() == MAIN_MENU_CLOSED && player.get_game_over() == false && world.get_pause() == GAME_NOT_PAUSED)
					{
						if (world.get_quit_game() == QUIT_CLOSED)
							world.set_quit_game(QUIT_OPENED);
					}
				}
				else if (event.key.keysym.sym == SDLK_y)
				{
					if (world.get_quit_game() == QUIT_OPENED)
					{
						world.set_quit_game(QUIT_CLOSED);
						world.set_main_menu(MAIN_MENU_OPENED);
						player.set_lives(0);
					}
				}
				else if (event.key.keysym.sym == SDLK_n)
				{
					if (world.get_quit_game() == QUIT_OPENED)
						world.set_quit_game(QUIT_CLOSED);
				}

				// Player can enter his name to save his score after he lost the game
				// Player's nick can consist of letters from a to z or form numbers 1 to 9, however player can click backspace to erase last letter from the nick
				if (player.get_game_over() == true && 
					((event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z) || (event.key.keysym.sym >= SDLK_1 && event.key.keysym.sym <= SDLK_9) || (event.key.keysym.sym == SDLK_BACKSPACE)) )
				{
					// Copying text from string to char*
					if (event.key.keysym.sym == SDLK_BACKSPACE)
					{
						if(name.length() >= 1)
							name.pop_back();
					}
					// -1 because of the NULL character at the end of the char player_name[]
					else if (name.length() < LETTERS_MAX_PLAYER_NICK-1)
						name += SDL_GetKeyName(event.key.keysym.sym);

					strcpy(player_name_draw, name.c_str());
					strcpy(player_name, name.c_str());
				}
				break;
			case SDL_KEYUP:
				break;
			case SDL_QUIT:
				quit = 1;
				break;

			}
		}
	}

	// freeing all surfaces
	// ******************************************************

	
	// cars
	for (int i = 0; i < CAR_NUMBER; i++)
		car[i].~Car();


	// turtles short
	// -----------------------
	for (int i = 0; i < NUMBER_SHORT_TURTLE; i++)
		turtle_short[i].~Turtle();
	// -----------------------
	// turtles long
	// -----------------------
	for (int i = 0; i < NUMBER_LONG_TURTLE; i++)
		turtle_long[i].~Turtle();
	// -----------------------


	// tree short
	// -----------------------
	for (int i = 0; i < TREE_SHORT_NUMBER; i++)
		tree_short[i].~Tree_trunk();
	// -----------------------
	// tree middle
	// -----------------------
	for (int i = 0; i < TREE_MIDDLE_NUMBER; i++)
		tree_middle[i].~Tree_trunk();
	// -----------------------
	// tree long
	// -----------------------
	for (int i = 0; i < TREE_LONG_NUMBER; i++)
		tree_long[i].~Tree_trunk();
	// -----------------------

	// ending spots
	// -----------------------
	for (int i = 0; i < ENDING_SPOTS_NUMBER; i++)
		ending_spots[i].~Ending_spot();
	// -----------------------

	// player
	// -----------------------
	player.~Player();
	// -----------------------
	
	// template
	// -----------------------
	SDL_FreeSurface(draw.get_charset_8x8());
	SDL_FreeSurface(draw.get_charset_20x20());
	SDL_FreeSurface(draw.get_screen());
	SDL_DestroyTexture(draw.get_scrtex());
	SDL_DestroyRenderer(draw.get_renderer());
	SDL_DestroyWindow(draw.get_window());
	// -----------------------

	// ******************************************************

	SDL_Quit();



	return 0;
};
