#include <SDL/SDL.h>
#include <math.h>
#include <stdio.h>

#include "libid/lib.h"
#include "env.h"
#include "vector.h"
#include "run.h"

void	paint_pixel(void* screen, Object* object, int pixel_x, int pixel_y,
		    double distance)
{
	(void)distance;
	setpixel(pixel_x, pixel_y, object->red, object->green, object->blue,
		 screen);
}

void	do_intersection(t_env* env, Ray* ray, int pixel_x, int pixel_y)
{
	int	is_inter;
	double	distance;
	Object*	objects;

	objects = env->objects;
	is_inter = 0;
	while (objects)
	{
		distance = 20000;
		if (objects->intersect && objects->type != OBJ_CAMERA)
			is_inter = objects->intersect(objects->object, ray,
						      &distance);
		if (is_inter)
			paint_pixel(env->screen, objects, pixel_x, pixel_y,
				    distance);
		objects = objects->next;
	}
}

void	throwray(t_env* env, Vector3D* origin, int pixel_x, int pixel_y)
{
	Vector3D	v;
	Ray		ray;

	v.x = pixel_x - (env->width / 2);
	v.y = pixel_y - (env->height / 2);
	v.z = - (env->width / (2 * tan(30 / 2)));
	vector_normalize(&v);
	ray.destination.x = v.x - origin->x;
	ray.destination.y = v.y - origin->y;
	ray.destination.z = v.z - origin->z;
	ray.origin.x = origin->x;
	ray.origin.y = origin->y;
	ray.origin.z = origin->z;
	vector_normalize(&ray.destination);
	//printf("Ray(%g, %g, %g)\n", ray.destination.x, ray.destination.y,
	//       ray.destination.z);
	do_intersection(env, &ray, pixel_x, pixel_y);
}

int	raytracer(t_env* env)
{
	Vector3D	origin;
	int		pixel_x;
	int		pixel_y;
	SDL_Surface*	screen;

	origin.x = 0;
	origin.y = 0;
	origin.z = 0;
	pixel_x = 0;
	pixel_y = 0;
	id_print("Calculating");
	while (pixel_y < env->height)
	{
		throwray(env, &origin, pixel_x, pixel_y);
		pixel_x = pixel_x + 1;
		if (pixel_x == env->width)
		{
			id_print(".");
			pixel_y = pixel_y + 1;
			pixel_x = 0;
		}
	}
	id_print("\n");
	screen = (SDL_Surface*)env->screen;
	SDL_UpdateRect(screen, 0, 0, 0, 0);
	id_print("Printing\n");
	return (0);
}

int	run(t_env* env)
{
	SDL_Event	event;

	if (raytracer(env))
		return (1);
	SDL_WaitEvent(&event);
	while (event.type != SDL_QUIT)
		SDL_WaitEvent(&event);
	return (0);
}
