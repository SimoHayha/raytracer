#include <SDL/SDL.h>

#include "libid/lib.h"
#include "env.h"
#include "input.h"
#include "init.h"

int	check_arg(int argc, char** argv)
{
	if (argc != 4)
	{
		id_print("Wrong argument count (%d)\n", argc);
		return (1);
	}
	if (id_atoi(argv[1]) < 0 || id_atoi(argv[2]) < 0)
	{
		id_print("Incorrect resolution, exiting ...\n");
		return (1);
	}
	return (0);
}

int	init_sdl(char** argv, t_env* env)
{
	int	width;
	int	height;

	width = id_atoi(argv[1]);
	height = id_atoi(argv[2]);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (1);
	atexit(SDL_Quit);
	env->screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
	if (!env->screen)
		return (1);
	initcolor(env->colors, env->screen);
	SDL_WM_SetCaption("Raytracer", NULL);
	return (0);
}

int	init(int argc, char** argv, t_env* env)
{
	if (check_arg(argc, argv))
		return (1);
	id_memset(env, 0, sizeof(*env));
	env->width = id_atoi(argv[1]);
	env->height = id_atoi(argv[2]);
	if (parsefile(&env->objects, argv[3]))
		return (1);
	if (init_sdl(argv, env))
		return (1);
	return (0);
}
