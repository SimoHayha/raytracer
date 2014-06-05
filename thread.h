#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>

#define WORKER_COUNT	20

typedef struct	s_env		t_env;
typedef struct	s_queue		t_queue;
typedef struct	s_object	t_object;

typedef struct	s_thread_pixel
{
	double	r;
	double	g;
	double	b;
	double	pixel_x;
	double	pixel_y;
}	t_thread_pixel;

typedef struct	s_thread_data
{
	int			id;
	int			alive;
	double			pixel_x_begin;
	double			pixel_y_begin;
	double			pixel_x_end;
	double			pixel_y_end;
	t_thread_pixel*		pixels;
	t_env*			env;
	pthread_mutex_t*	start_lock;
	pthread_mutex_t*	queue_lock;
	pthread_mutex_t*	output_lock;
	pthread_mutex_t*	work_lock;
	pthread_mutex_t*	pixel_lock;
}	t_thread_data;

int	build_thread(t_env* env);

#endif
