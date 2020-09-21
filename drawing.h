#ifndef drawing_h
#define drawing_h
#include "structures.h"
extern "C"
{
#include "SDL2-2.0.10/include/SDL.h"
#include "SDL2-2.0.10/include/SDL_main.h"
}

class Draw
{
private:
	SDL_Surface* screen;
	SDL_Texture* scrtex;
	SDL_Window* window;
	SDL_Renderer* renderer;
	// Different sizes of the text
	SDL_Surface* charset_8x8;
	SDL_Surface* charset_20x20;

	// colors
	int black;
	int green;
	int red;
	int blue;

public:
	// draw a text txt on surface screen, starting from the point (x, y)
	// charset is a 128x128 bitmap containing character images
	void draw_string(position_t pos, const char* text, int size);

	// draw a surface sprite on a surface screen in point (x, y)
	// (x, y) is the center of sprite on screen
	void draw_surface(SDL_Surface* sprite, struct position_t pos);

	// draw a single pixel
	void draw_pixel(position_t pos, Uint32 color);

	// draw a vertical (when dx = 0, dy = 1) or horizontal (when dx = 1, dy = 0) line
	void draw_line(int x, int y, int l, int dx, int dy, Uint32 color);

	// draw a rectangle of size l by k
	void draw_rectangle(int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor);

	int load_bmp(struct SDL_Surface** object, char* src);

	// GETTING VARIABLES
	// ************************************************************
	SDL_Surface* get_screen();
	SDL_Texture* get_scrtex();
	SDL_Window* get_window();
	SDL_Renderer* get_renderer();
	SDL_Surface** get_screen_address();
	SDL_Texture** get_scrtex_address();
	SDL_Window** get_window_address();
	SDL_Renderer** get_renderer_address();
	SDL_Surface** get_charset_8x8_address();
	SDL_Surface* get_charset_8x8();
	SDL_Surface** get_charset_20x20_address();
	SDL_Surface* get_charset_20x20();

	int get_color_black();
	void set_color_black(int c);

	int get_color_green();
	void set_color_green(int c);

	int get_color_red();
	void set_color_red(int c);

	int get_color_blue();
	void set_color_blue(int c);


	void set_screen(SDL_Surface* temp);
	void set_scrtex(SDL_Texture* temp);
	// ************************************************************

};



#endif // drawing_h

