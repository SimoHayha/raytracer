#include <SDL/SDL.h>

#include "setpixel.h"

void	setpixel(int x, int y, unsigned char red, unsigned char green,
		 unsigned char blue, void* p_screen)
{
	SDL_Surface*	screen;
	Uint32		color;

	screen = (SDL_Surface*)p_screen;
	color = SDL_MapRGB(screen->format, red, green, blue);
	color = SDL_MapRGB(screen->format, 255, 0, 0);
	*((Uint32*)(screen->pixels) + x + y * screen->w) = color;
	//SDL_UpdateRect(screen, 0, 0, 0, 0);
}

void	initcolor(Uint32 colors[NB_COLORS], void* p_screen)
{
	SDL_Surface*	screen;

	screen = (SDL_Surface*)p_screen;
	colors[C_BLACK] = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	colors[C_DARK_BLUE] = SDL_MapRGB(screen->format, 0x00, 0x00, 0x80);
	colors[C_DARK_GREEN] = SDL_MapRGB(screen->format, 0x00, 0x80, 0x00);
	colors[C_DARK_CYAN] = SDL_MapRGB(screen->format, 0x00, 0x80, 0x80);
	colors[C_DARK_RED] = SDL_MapRGB(screen->format, 0x80, 0x00, 0x00);
	colors[C_DARK_MAGENTA] = SDL_MapRGB(screen->format, 0x80, 0x00, 0x80);
	colors[C_LIGHT_GRAY] = SDL_MapRGB(screen->format, 0xC0, 0xC0, 0xC0);
	colors[C_GRAY] = SDL_MapRGB(screen->format, 0x80, 0x80, 0x80);
	colors[C_BLUE] = SDL_MapRGB(screen->format, 0x00, 0x00, 0xFF);
	colors[C_GREEN] = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	colors[C_CYAN] = SDL_MapRGB(screen->format, 0x00, 0xFF, 0xFF);
	colors[C_RED] = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	colors[C_MAGENTA] = SDL_MapRGB(screen->format, 0xFF, 0x00, 0xFF);
	colors[C_YELLOW] = SDL_MapRGB(screen->format, 0xFF, 0xFF, 0x00);
	colors[C_WHITE] = SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF);
}
