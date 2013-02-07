#ifndef __SETPIXEL_H__
#define __SETPIXEL_H__

enum
{
	C_BLACK,
	C_DARK_BLUE,
	C_DARK_GREEN,
	C_DARK_CYAN,
	C_DARK_RED,
	C_DARK_MAGENTA,
	C_GRAY,
	C_LIGHT_GRAY,
	C_BLUE,
	C_GREEN,
	C_CYAN,
	C_RED,
	C_MAGENTA,
	C_YELLOW,
	C_WHITE,
	NB_COLORS
};

void	setpixel(int x, int y, unsigned char red, unsigned char green,
		 unsigned char blue, void* p_screen);
void	initcolor(Uint32 colors[NB_COLORS], void* p_screen);

#endif
