#include <libidX.h>
#include <stdlib.h>
#include <stdio.h>

#include "math_function.h"
#include "calculate_ray.h"
#include "translation.h"
#include "raytracer.h"
#include "libid/lib.h"
#include "thread.h"
#include "object.h"
#include "vector.h"
#include "matrix.h"
#include "scene.h"
#include "color.h"
#include "run.h"
#include "env.h"

void	render(t_env* env)
{
	int		i;
	int		max;

	id_print("\nRendering ...\n");
	max = env->width * env->height;
	i = 0;
	while (i < max)
	{
		idx_setpixel(env->screen, env->pixels[i].r, env->pixels[i].g, env->pixels[i].b, env->pixels[i].pixel_x, env->pixels[i].pixel_y);
		i = i + 1;
	}
}

void	join_thread(t_env* env)
{
	int	i;
	void*	ret;

	i = 0;
	while (i < WORKER_COUNT)
	{
		pthread_join(env->thread[i], &ret);
		i = i + 1;
	}
}

int	run(t_env* env)
{
	id_print("Calculating ...\n");
	join_thread(env);
	render(env);
	idx_run(env->screen);
	idx_clear(env->screen);
	return (0);
}
