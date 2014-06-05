#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <libidX.h>

#include "env.h"
#include "queue.h"
#include "libid/lib.h"
#include "raytracer.h"
#include "antialiasing.h"
#include "thread.h"

void*		start_routine(void* data)
{
	double		real_x;
	double		real_y;
	t_thread_data*	my_data;
	double		offset;

	my_data = (t_thread_data*)data;
	real_x = my_data->pixel_x_begin;
	real_y = my_data->pixel_y_begin;
	offset = (1 / ((double)ANTIALIASING));
	while (real_x < my_data->pixel_x_end)
	{
		antialiasing(my_data, real_x, real_y, offset);
		real_y = real_y + 1;
		if (real_y >= my_data->pixel_y_end)
		{
			real_y = my_data->pixel_y_begin;
			real_x = real_x + 1;
		}
	}
	pthread_exit(NULL);
	return (NULL);
}

static void	set_data(t_thread_data* data, t_env* env, int i, double x)
{
	data->id = i + 1;
	data->alive = 1;
	data->pixel_x_begin = (x * i);
	data->pixel_x_end = (x * (i + 1));
	data->pixel_y_begin = 0;
	data->pixel_y_end = env->height;
	data->pixels = env->pixels;
	data->env = env;
}

t_thread_data*	build_thread_data(t_env* env)
{
	t_thread_data*	data;
	int		i;
	double		x;

	data = malloc(sizeof(*data) * WORKER_COUNT);
	i = 0;
	if (!data)
		return (NULL);
	x = env->width / WORKER_COUNT;
	while (i < WORKER_COUNT)
	{
		set_data(&data[i], env, i, x);
		i = i + 1;
	}
	return (data);
}

int		build_thread(t_env* env)
{
	int		i;
	int		rc;

	i = 0;
	env->thread_data = build_thread_data(env);
	if (!env->thread_data)
		return (1);
	while (i < WORKER_COUNT)
	{
		rc = pthread_create(&env->thread[i], NULL, &start_routine,
				    (void*)(&env->thread_data[i]));
		if (rc != 0)
			return (1);
		i =i + 1;
	}
	return (0);
}
