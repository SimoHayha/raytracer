#include <math.h>
#include <libidX.h>
#include <stdio.h>

#include "libid/lib.h"
#include "vector.h"
#include "env.h"
#include "translation.h"
#include "object.h"
#include "reflection.h"
#include "refraction.h"
#include "calculate_ray.h"
#include "raytracer_utils.h"
#include "raytracer.h"

void		print_progress(t_env* env)
{
	int	tmp;

	env->global_work = env->global_work + 1;
	tmp = (env->global_work / env->scale) * 10;
	if (tmp > env->current_work)
	{
		env->current_work = tmp;
		id_print("\r[%d%]", tmp);
	}
}

t_object*	get_intersect(t_env* env, t_ray* r)
{
	t_object*	obj;
	t_object*	objs;

	obj = NULL;
	objs = env->objects;
	while (objs != NULL)
	{
		if (objs->intersect != NULL &&
		    objs->intersect(objs, r))
			obj = objs;
		objs = objs->next;
	}
	return (obj);
}

int		ray_trace(t_env* env, t_ray* ray, t_color* clr, int depth)
{
	t_object*	obj;
	t_point		inter;
	t_point		real_inter;
	t_ray		new_ray;

	if (init_color_depth(clr, depth))
		return (0);
	obj = get_intersect(env, ray);
	if (obj == NULL)
		return (0);
	init_raytrace(ray, &inter, env, &real_inter);
	if (obj->color != NULL)
		obj->color(ray, &real_inter, obj, clr);
	calculate_color(env, &real_inter, &obj, clr);
	if (obj->material.reflect)
	{
		get_reflected_ray(ray, obj, &new_ray);
		if (ray_trace(env, &new_ray, clr, depth + 1))
			apply_coef(clr, obj);
	}
	if (obj->material.refract > 0.0)
	{
		get_refracted_ray(ray, obj, &new_ray);
		ray_trace(env, &new_ray, clr, depth + 1);
	}
	return (apply_color(clr));
}

int		raytracer(t_thread_data* thread, double x, double y, t_thread_pixel* pixel)
{
	t_env*	env;
	t_ray	r;
	t_color	clr;

	env = thread->env;
	r.in_obj = 0;
	r.refract = 1.0;
	r.distance = 20000;
	id_memset(&clr, 0, sizeof(clr));
	get_point(&env->camera, &r.dest, x, y);
	normalize(&r.dest);
	get_translation_vect(&env->camera.transform, &r.dest, &r.dest);
	normalize(&r.dest);
	copy_vector(&r.origin, &env->camera.pos);
	ray_trace(env, &r, &clr, 0);
	if (r.distance <= env->camera.viewplane_dist)
		id_memset(&clr, 0, sizeof(clr));
	pixel->r = clr.r;
	pixel->g = clr.g;
	pixel->b = clr.b;
	pixel->pixel_x = x;
	pixel->pixel_y = y;
	return (0);
}
