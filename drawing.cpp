#include <stdio.h>
#include "drawing.h"
#include "structures.h"
#include "constants.h"


void Draw::draw_string(position_t pos, const char* text, int size)
{
	int px, py, c;
	SDL_Rect s, d;
	s.w = size;
	s.h = size;
	d.w = size;
	d.h = size;
	while (*text)
	{
		c = *text & 255;
		px = (c % 16) * size;
		py = (c / 16) * size;
		s.x = px;
		s.y = py;
		d.x = pos.x;
		d.y = pos.y;
		if(size == 8)
			SDL_BlitSurface(charset_8x8, &s, screen, &d);
		else
			SDL_BlitSurface(charset_20x20, &s, screen, &d);

		pos.x += size;
		text++;
	}
}

void Draw::draw_surface(SDL_Surface* sprite, struct position_t pos) 
{
	SDL_Rect dest;
	dest.x = pos.x - sprite->w / 2;
	dest.y = pos.y - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
}

void Draw::draw_pixel(position_t pos, Uint32 color)
{
	int bpp = screen->format->BytesPerPixel;
	Uint8* p = (Uint8*)screen->pixels + pos.y * screen->pitch + pos.x * bpp;
	*(Uint32*)p = color;
}

void Draw::draw_line(int x, int y, int l, int dx, int dy, Uint32 color)
{
	position_t pos;
	pos.x = x;
	pos.y = y;
	for (int i = 0; i < l; i++)
	{
		draw_pixel(pos, color);
		pos.x += dx;
		pos.y += dy;
	}
}

void Draw::draw_rectangle(int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor)
{
	int i;
	draw_line(x, y, k, 0, 1, outlineColor);
	draw_line(x + l - 1, y, k, 0, 1, outlineColor);
	draw_line(x, y, l, 1, 0, outlineColor);
	draw_line(x, y + k - 1, l, 1, 0, outlineColor);
	for (i = y + 1; i < y + k - 1; i++)
		draw_line(x + 1, i, l - 2, 1, 0, fillColor);
}

int Draw::load_bmp(struct SDL_Surface** object, char* src)
{
	// loading image cs8x8.bmp
	*object = SDL_LoadBMP(src);
	if (*object == NULL)
	{
		printf("SDL_LoadBMP(%s) error: %s\n", src, SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return LOADING_ERROR;
	}
	SDL_SetColorKey(*object, true, 0x000000);
	return LOADING_OK;
}

SDL_Surface* Draw::get_screen()
{
	return screen;
}

SDL_Texture* Draw::get_scrtex()
{
	return scrtex;
}

SDL_Window* Draw::get_window()
{
	return window;
}

SDL_Renderer* Draw::get_renderer()
{
	return renderer;
}

SDL_Surface** Draw::get_screen_address()
{
	return &screen;
}

SDL_Texture** Draw::get_scrtex_address()
{
	return &scrtex;
}

SDL_Window** Draw::get_window_address()
{
	return &window;
}

SDL_Renderer** Draw::get_renderer_address()
{
	return &renderer;
}

void Draw::set_screen(SDL_Surface* temp)
{
	screen = temp;
}

void Draw::set_scrtex(SDL_Texture* temp)
{
	scrtex = temp;
}

SDL_Surface** Draw::get_charset_8x8_address()
{
	return &charset_8x8;
}

SDL_Surface* Draw::get_charset_8x8()
{
	return charset_8x8;
}

SDL_Surface** Draw::get_charset_20x20_address()
{
	return &charset_20x20;
}

SDL_Surface* Draw::get_charset_20x20()
{
	return charset_20x20;
}

int Draw::get_color_black()
{
	return black;
}
void Draw::set_color_black(int c)
{
	black = c;
}

int Draw::get_color_green()
{
	return green;
}
void Draw::set_color_green(int c)
{
	green = c;
}

int Draw::get_color_red()
{
	return red;
}
void Draw::set_color_red(int c)
{
	red = c;
}

int Draw::get_color_blue()
{
	return blue;
}
void Draw::set_color_blue(int c)
{
	blue = c;
}