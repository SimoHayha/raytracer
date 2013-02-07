#ifndef __ENV_H__
#define __ENV_H__

#include "setpixel.h"
#include "object.h"

typedef struct	s_env
{
	int	width;
	int	height;
	void*	screen;
	Uint32	colors[NB_COLORS];
	Object*	objects;
}	t_env;

#endif
