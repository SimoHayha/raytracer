#ifndef __ENV_H__
#define __ENV_H__

#include <pthread.h>

#include "camera.h"
#include "thread.h"

#define DIFFUSE_LIGHT	1.0f
#define ANTIALIASING	4

typedef struct	s_object	t_object;
typedef struct	s_sphere	t_sphere;
typedef struct	s_plane		t_plane;
typedef struct	s_cylinder	t_cylinder;
typedef struct	s_pixel		t_pixel;
typedef struct	s_queue		t_queue;
typedef struct	s_thread_data	t_thread_data;
typedef struct	s_thread_pixel	t_thread_pixel;
typedef struct	s_light		t_light;

typedef struct	s_env
{
	int		global_work;
	int		current_work;
	int		scale;
	int		width;
	int		height;
	void*		screen;
	t_object*	objects;
	t_camera	camera;
	t_sphere*	spheres;
	t_cylinder*	cylinders;
	t_thread_data*	thread_data;
	t_thread_pixel*	pixels;
	t_light*	lights;
	pthread_t	thread[WORKER_COUNT];
}	t_env;

#endif
