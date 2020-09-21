#ifndef constants_h
#define constants_h

// SCREEN SIZES
// ************************************************************
#define SCREEN_WIDTH	660
#define SCREEN_HEIGHT	896

#define SCREEN_EDGE_LEFT -900
#define SCREEN_EDGE_RIGHT 900
// ************************************************************


// MOVING ELEMENTS
// ************************************************************
#define LEFT -1
#define RIGHT 1
// ************************************************************



// HOW MANY OF BACKGROUND LINES WILL BE DRAWN
// ************************************************************
#define FIVE_LINES 5
#define TWO_LINES 2
// ************************************************************



// START COORINATES OF BACKGROUND IMAGES (WHERE THER ARE GOING TO BE DRAWN AT FIRST)
// ************************************************************

// X COORDINATES
//------------
#define WORLD_START_POS_X 30 // TO BACKGROUND EVERYTHING BUT FLOWERS
#define FLOWERS_START_POS_X 0
// ------------

// Y COORDINATES
// ------------
#define PAVEMENT_1_START_POS_Y SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA/2 
#define PAVEMENT_2_START_POS_Y SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*6 - DRAW_DELTA/2 
#define ROUTE_START_POS_Y SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*1 - DRAW_DELTA/2  
#define WATER_START_POS_Y SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*7 - DRAW_DELTA/2  
#define FLOWERS_START_POS_Y SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*12 - DRAW_DELTA/2  
#define PLAYER_LIVES_POS_Y SCREEN_HEIGHT - DRAW_DELTA/2 
// ------------
// ************************************************************



// TEXT SIZES
// ************************************************************
#define TEXT_SIZE_8 8
#define TEXT_SIZE_20 20
// ************************************************************

// TIME
//************************************************************
#define TIME_LEVEL 50
#define TIME_RED_LEVEL 10

#define TIME_BAR_HEIGHT 40

#define TIME_BAR_POSITION_X SCREEN_WIDTH - TIME_LEVEL * 4
#define TIME_BAR_POSITION_Y SCREEN_HEIGHT - TIME_BAR_HEIGHT - 10
//************************************************************

#define DRAW_LEVEL_COMPLETED_TIME 2



// ************************************************************
#define GAME_PAUSED true
#define GAME_NOT_PAUSED false

#define MAIN_MENU_OPENED true
#define MAIN_MENU_CLOSED false

#define HIGH_SCORES_OPENED true
#define HIGH_SCORES_CLOSED false

#define QUIT_OPENED true
#define QUIT_CLOSED false
// ************************************************************


// MENU
// ************************************************************

// MENU POINTER
// ------------
#define POINTER_WIDTH 16
// ------------

// GAME OVER MENU
// ------------
#define GAME_OVER_MENU_CHOICES_NUMBER 3
#define LETTERS_MAX_PLAYER_NICK 27 // THESE LETTERS ARE ALSO: "ENTER YOUR NICK: "
// ------------

// MAIN MENU
// ------------
#define MAIN_MENU_CHOICES_NUMBER 3
// ------------

// ************************************************************


// LOADING FUNCTIONS RETURN STATUS
// ************************************************************
#define LOADING_ERROR 1
#define LOADING_OK 0
// ************************************************************



// MAIN LOOP END OR DONT END
// ************************************************************
#define EXIT_PROGRAM_WITH_ERROR 1
#define EXIT_PROGRAM 0
#define DONT_EXIT_PROGRAM -1
// ************************************************************



// SPRITE PATHS
// ************************************************************
// PLAYER
// ------------
#define PATH_PLAYER_UP_SPRITE "GameGraphics/frog_up.bmp"
#define PATH_PLAYER_UP_MOVE_SPRITE "GameGraphics/frog_up_move.bmp"
#define PATH_PLAYER_DOWN_SPRITE "GameGraphics/frog_down.bmp"
#define PATH_PLAYER_DOWN_MOVE_SPRITE "GameGraphics/frog_down_move.bmp"
#define PATH_PLAYER_RIGHT_SPRITE "GameGraphics/frog_right.bmp"
#define PATH_PLAYER_RIGHT_MOVE_SPRITE "GameGraphics/frog_right_move.bmp"
#define PATH_PLAYER_LEFT_SPRITE "GameGraphics/frog_left.bmp"
#define PATH_PLAYER_LEFT_MOVE_SPRITE "GameGraphics/frog_left_move.bmp"
// ------------

// TEXT
// ------------
#define PATH_CHARSET_8x8 "GameGraphics/cs8x8.bmp"
#define PATH_CHARSET_20x20 "GameGraphics/cs20x20.bmp"
// ------------

// BACKGROUND
// ------------
#define PATH_PAVEMENT_SPRITE "GameGraphics/pavement.bmp"
#define PATH_WATER_SPRITE "GameGraphics/water.bmp"
#define PATH_FLOWERS_SPRITE "GameGraphics/flowers.bmp"
#define PATH_LILY_SPRITE "GameGraphics/lily.bmp"
#define PATH_LILY_BUSY_SPRITE "GameGraphics/lily_busy.bmp"
#define PATH_ROUTE_SPRITE "GameGraphics/route.bmp"
// ------------

// CARS
// ------------
#define PATH_CAR_1_LEFT_1_SPRITE "GameGraphics/car_1_left_1.bmp"
#define PATH_CAR_1_LEFT_2_SPRITE "GameGraphics/car_1_left_2.bmp"
#define PATH_CAR_1_LEFT_3_SPRITE "GameGraphics/car_1_left_3.bmp"
#define PATH_CAR_1_LEFT_4_SPRITE "GameGraphics/car_1_left_4.bmp"
#define PATH_CAR_1_LEFT_5_SPRITE "GameGraphics/car_1_left_5.bmp"
#define PATH_CAR_1_LEFT_6_SPRITE "GameGraphics/car_1_left_6.bmp"

#define PATH_CAR_1_RIGHT_1_SPRITE "GameGraphics/car_1_right_1.bmp"
#define PATH_CAR_1_RIGHT_2_SPRITE "GameGraphics/car_1_right_2.bmp"
#define PATH_CAR_1_RIGHT_3_SPRITE "GameGraphics/car_1_right_3.bmp"
#define PATH_CAR_1_RIGHT_4_SPRITE "GameGraphics/car_1_right_4.bmp"
#define PATH_CAR_1_RIGHT_5_SPRITE "GameGraphics/car_1_right_5.bmp"
#define PATH_CAR_1_RIGHT_6_SPRITE "GameGraphics/car_1_right_6.bmp"

#define PATH_CAR_2_LEFT_1_SPRITE "GameGraphics/car_2_left_1.bmp"
#define PATH_CAR_2_RIGHT_1_SPRITE "GameGraphics/car_2_right_1.bmp"
// ------------

// TREES
// ------------
#define PATH_TREE_TRUNK_SHORT "GameGraphics/tree_trunk_short.bmp"
#define PATH_TREE_TRUNK_MIDDLE "GameGraphics/tree_trunk_middle.bmp"
#define PATH_TREE_TRUNK_LONG "GameGraphics/tree_trunk_long.bmp"
// ------------

// TURTLES
// ------------
#define PATH_TURTLE_SHORT_1 "GameGraphics/turtle_short.bmp"
#define PATH_TURTLE_SHORT_2 "GameGraphics/turtle_short_2.bmp"
#define PATH_TURTLE_SHORT_DIVE_1 "GameGraphics/turtle_short_dive_1.bmp"
#define PATH_TURTLE_SHORT_DIVE_2 "GameGraphics/turtle_short_dive_2.bmp"
#define PATH_TURTLE_SHORT_DIVE_3 "GameGraphics/turtle_short_dive_3.bmp"
#define PATH_TURTLE_SHORT_DIVE_4 "GameGraphics/turtle_short_dive_4.bmp"
#define PATH_TURTLE_SHORT_DIVE_all "GameGraphics/turtle_short_dive_all.bmp"

#define PATH_TURTLE_LONG_1 "GameGraphics/turtle_long.bmp"
#define PATH_TURTLE_LONG_2 "GameGraphics/turtle_long_2.bmp"
#define PATH_TURTLE_LONG_DIVE_1 "GameGraphics/turtle_long_dive_1.bmp"
#define PATH_TURTLE_LONG_DIVE_2 "GameGraphics/turtle_long_dive_2.bmp"
#define PATH_TURTLE_LONG_DIVE_3 "GameGraphics/turtle_long_dive_3.bmp"
#define PATH_TURTLE_LONG_DIVE_4 "GameGraphics/turtle_long_dive_4.bmp"
#define PATH_TURTLE_LONG_DIVE_all "GameGraphics/turtle_long_dive_all.bmp"
// ------------

// MENU
// ------------
#define PATH_MENU_POINTER "GameGraphics/pointer.bmp"
// ------------

// FILES
// ------------
#define PATH_HIGH_SCORES "high_scores.txt"
// ------------


// ************************************************************



// DRAWING SPACE
// ************************************************************
#define DRAW_DELTA 60
// ************************************************************



// POINTS
// ************************************************************
#define AMOUNT_OF_HIGH_SCORES 10
#define POINTS_TIME_MULTIPLIER 10
#define POINTS_ADDED_CLOSER 10
#define POINTS_SPOT_COMPLETED 50

#define POINTS_POSITION_X SCREEN_WIDTH/2 - 8*16
#define POINTS_POSITION_Y SCREEN_HEIGHT - DRAW_DELTA/2
#define MAX_POINTS_TEXT 18
// ************************************************************


// ANIMATION
// ************************************************************
#define ANIMATION_LENGTH 20
// ************************************************************


// PLAYER FEATURES
// ************************************************************
enum direction_t
{
	NO_MOVEMENT,
	UP_DIR,
	DOWN_DIR,
	RIGHT_DIR,
	LEFT_DIR
};

#define PLAYER_MAX_LEFT_WATER 0
#define PLAYER_MAX_RIGHT_WATER SCREEN_WIDTH
#define PLAYER_START_POS_X SCREEN_WIDTH/2
#define PLAYER_START_POS_Y SCREEN_HEIGHT - SCREEN_HEIGHT/14 - 30 

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 50

#define PLAYER_JUMP 3

#define PLAYER_LIVES 3
#define PLAYER_0_LIVES 0
#define MAX_POS_LEFT 30
#define MAX_POS_RIGHT 630
#define MAX_POS_UP 82
#define MAX_POS_DOWN SCREEN_HEIGHT - SCREEN_HEIGHT/14 - 30

// PLAYER CONTROLLING
// ------------
#define PLAYER_MOVE_UP true
#define PLAYER_MOVE_DOWN false
#define PLAYER_MOVE_LEFT true
#define PLAYER_MOVE_RIGHT false
// ------------
// ------------

// ************************************************************

// CARS FEATURES
// ************************************************************
#define CAR_ANIMATE_SRPITES_MAX_NUMBER 6
#define CAR_1_LEFT_ANIMATE_SRPITES_MAX_NUMBER 6
#define CAR_1_RIGHT_ANIMATE_SRPITES_MAX_NUMBER 6
#define CAR_2_LEFT_ANIMATE_SRPITES_MAX_NUMBER 1
#define CAR_2_RIGHT_ANIMATE_SRPITES_MAX_NUMBER 1

#define CAR_ANIMATION_LENGTH 10

#define CAR_1_WIDTH 60
#define CAR_2_WIDTH 120
#define CAR_HEIGHT 50


// CAR 1 LEFT
// ------------
#define CAR_1_LEFT 1 // ID
#define SPEED_CAR_1_LEFT 1
#define SPEED_DELAY_CAR_1_LEFT 1
// ------------

// CAR 1 RIGHT
// ------------
#define CAR_1_RIGHT 2 // ID
#define SPEED_CAR_1_RIGHT 1
#define SPEED_DELAY_CAR_1_RIGHT 2
// ------------

// CAR 2 LEFT
// ------------
#define CAR_2_LEFT 3 // ID
#define SPEED_CAR_2_LEFT 1
#define SPEED_DELAY_CAR_2_LEFT 2
// ------------

// CAR 2 RIGHT
// ------------
#define CAR_2_RIGHT 4 // ID
#define SPEED_CAR_2_RIGHT 1
#define SPEED_DELAY_CAR_2_RIGHT 3
// ------------

#define CAR_ROUTE_1_DRAW_DELTA DRAW_DELTA * 1
#define CAR_ROUTE_2_DRAW_DELTA DRAW_DELTA * 1
#define CAR_ROUTE_3_DRAW_DELTA DRAW_DELTA * 1
#define CAR_ROUTE_4_DRAW_DELTA DRAW_DELTA * 1
#define CAR_ROUTE_5_DRAW_DELTA DRAW_DELTA * 1


// CAR ROUTES Y
// ------------
#define CAR_ROUTE_1 SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*1 - DRAW_DELTA/2 // CAR MODEL 1
#define CAR_ROUTE_2 SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*2 - DRAW_DELTA/2 // CAR MODEL 2
#define CAR_ROUTE_3	SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*3 - DRAW_DELTA/2 // CAR MODEL 1
#define CAR_ROUTE_4 SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*4 - DRAW_DELTA/2 // CAR MODEL 2
#define CAR_ROUTE_5 SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*5 - DRAW_DELTA/2 // CAR MODEL 1
// ------------

// there is no number for each car model 1 and car model 2 because CAR_NUMBER will be divided equally for both models
#define CAR_NUMBER 25

// ************************************************************

// TREE TRUNKS FEATURES
// ************************************************************


#define TREE_SHORT_WIDTH 140
#define TREE_MIDDLE_WIDTH 200
#define TREE_LONG_WIDTH 260
#define TREE_HEIGHT 50

// TREE TRUNK SHORT
// ------------
#define TREE_SHORT 1 // ID
#define SPEED_TREE_SHORT 1
#define SPEED_DELAY_TREE_SHORT 5
#define TREE_SHORT_NUMBER 5
#define DRAW_DELTA_SHORT_TREE DRAW_DELTA * 6

// ------------

// TREE TRUNK MIDDLE
// ------------
#define TREE_MIDDLE 2 // ID
#define SPEED_TREE_MIDDLE 1
#define SPEED_DELAY_TREE_MIDDLE 3
#define TREE_MIDDLE_NUMBER 4
#define DRAW_DELTA_MIDDLE_TREE DRAW_DELTA * 7

// ------------

// TREE TRUNK LONG
// ------------
#define TREE_LONG 3 // ID
#define SPEED_TREE_LONG 1
#define SPEED_DELAY_TREE_LONG 2
#define TREE_LONG_NUMBER 3
#define DRAW_DELTA_LONG_TREE DRAW_DELTA * 10

// ------------


// TREES ROUTES Y
// ------------
#define SHORT_TREE_ROUTE SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*8 - DRAW_DELTA/2
#define MIDDLE_TREE_ROUTE SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*11 - DRAW_DELTA/2 
#define LONG_TREE_ROUTE SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*9 - DRAW_DELTA/2 
// ------------

#define ALL_TREE_NUMBER TREE_SHORT_NUMBER + TREE_LONG_NUMBER + TREE_MIDDLE_NUMBER

// ************************************************************



// TURTLES FEATURES
// ************************************************************

#define DIVE true
#define NOT_DIVE false

#define TURTLE_SHORT_WIDTH 100
#define TURTLE_LONG_WIDTH 170
#define TURTLE_HEIGHT 50

#define TURTLE_ANIMATE_SRPITES_MAX_NUMBER 10
#define TURTLE_SHORT_DIVE_ANIMATE_SRPITES_MAX_NUMBER 10
#define TURTLE_SHORT_NOT_DIVE_ANIMATE_SRPITES_MAX_NUMBER 2
#define TURTLE_LONG_DIVE_ANIMATE_SRPITES_MAX_NUMBER 10
#define TURTLE_LONG_NOT_DIVE_ANIMATE_SRPITES_MAX_NUMBER 2

#define TURTLE_ANIMATION_LENGTH 40

// TURTLES SHORT
// ------------
#define TURTLE_SHORT 1 // ID
#define SPEED_TURTLE_SHORT 1
#define SPEED_DELAY_TURTLE_SHORT 3
#define NUMBER_SHORT_TURTLE 7
#define DRAW_DELTA_SHORT_TURTLE DRAW_DELTA * 4
// ------------

// TURTLES LONG
// ------------
#define TURTLE_LONG 2 // ID
#define SPEED_TURTLE_LONG 1
#define SPEED_DELAY_TURTLE_LONG 2
#define NUMBER_LONG_TURTLE 5
#define DRAW_DELTA_LONG_TURTLE DRAW_DELTA * 6
// ------------


// TURTLES ROUTES Y
// ------------
#define TURTLE_SHORT_ROUTE SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*10 - DRAW_DELTA/2
#define TURTLE_LONG_ROUTE SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*7 - DRAW_DELTA/2 
// ------------


#define ALL_TURTLE_NUMBER NUMBER_SHORT_TURTLE + NUMBER_LONG_TURTLE
// ************************************************************


// ENDING SPOTS FEATURES
// ************************************************************
#define ENDING_SPOTS_NUMBER 5

#define ENDING_SPOT_WIDTH 10
#define ENDING_SPOT_HEIGHT 50

#define ENDING_SPOT_NUMBER 5
#define ENDING_SPOT_1_POS_X 90
#define ENDING_SPOT_POS_Y SCREEN_HEIGHT - SCREEN_HEIGHT/14 - DRAW_DELTA*12 - DRAW_DELTA/2  

// ************************************************************


#endif // constants_h
