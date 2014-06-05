#include <fcntl.h>
#include <stdlib.h>
#include <libidX.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "libid/lib.h"
#include "cylinder.h"
#include "camera.h"
#include "sphere.h"
#include "thread.h"
#include "light.h"
#include "plane.h"
#include "init.h"
#include "env.h"

int	handle_input(t_env* env, char* line)
{
	char**	input;
	int	nb_args;

	input = id_strwordtab(line, " \t", &nb_args);
	if (input == NULL)
		return (-1);
	if (id_strcmp(input[0], "c") == 0)
		return (fill_camera(env, input, nb_args));
	else if (id_strcmp(input[0], "S") == 0)
		return (new_sphere(env, input, nb_args));
	else if (id_strcmp(input[0], "P") == 0)
		return (new_plane(env, input, nb_args));
	else if (id_strcmp(input[0], "C") == 0)
		return (new_cylinder(env, input, nb_args));
	else if (id_strcmp(input[0], "Li") == 0)
		return (new_light(env, input, nb_args));
	id_wordtabfree(input);
	return (0);
}

int	init_input(t_env* env, char* file)
{
	int	fd;
	char*	buf;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (id_perror(file));
	buf = id_getline(fd);
	while (buf != NULL)
	{
		if (handle_input(env, buf))
		{
			free(buf);
			if (close(fd) < 0)
				return (id_perror(NULL));
			return (-1);
		}
		free(buf);
		buf = id_getline(fd);
	}
	if (close(fd) < 0)
		return (id_perror(NULL));
	return (0);
}

int	init(int argc, char** argv, t_env* env)
{
	id_memset(env, 0, sizeof(*env));
	if (argc != 4)
		return (id_error("id_rt width height fileToLoad"));
	env->width = id_atoi(argv[1]);
	env->height = id_atoi(argv[2]);
	if (env->height <= 0 || env->width <= 0)
		return (id_error("width and height should be over 0"));
	if (init_input(env, argv[3]))
		return (-1);
	env->screen = idx_init("Raytracing", env->width,
			       env->height);
	if (env->screen == NULL)
		return (-1);
	env->pixels = malloc(sizeof(*env->pixels) * (env->width * env->height));
	if (!env->pixels)
		return (-1);
	if (build_thread(env))
		return (-1);
	env->global_work = 0;
	env->scale = (((env->width * env->height) / 10) * (ANTIALIASING / 2)) * 2;
	env->current_work = 0;
	return (0);
}
