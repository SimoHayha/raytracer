#include "libid/lib.h"
#include "vector.h"
#include "object.h"
#include "color.h"
#include "plane.h"
#include "light.h"
#include "env.h"

int	is_under_light(t_object* objs, t_object** obj, t_ray* light_ray)
{
	t_object*	obstacle;

	obstacle = NULL;
	while (objs != NULL)
	{
		if (objs != *obj && objs->intersect(objs, light_ray))
			obstacle = objs;
		objs = objs->next;
	}
	if (obstacle == NULL)
		return (1);
	return (0);
}

double	calculate_angle(t_ray* light_ray, t_object* obj, t_point* inter)
{
	t_vector	normal;
	t_vector	light;
	double		angle;

	get_normal(obj, inter, &normal, light_ray);
	sub_vector(NULL, &light_ray->dest, &light);
	angle = dot_vector(&light, &normal);
	if (angle <= 0.0)
		angle = 0.0;
	return (angle);
}

double	light_color_diff(t_object** obj, t_point* inter, t_object* objects,
			 t_light* light)
{
	t_ray		light_ray;

	light_ray.distance = 20000;
	copy_vector(&light_ray.origin, &light->pos);
	get_vector(&light->pos, inter, &light_ray.dest);
	normalize(&light_ray.dest);
	(*obj)->intersect(*obj, &light_ray);
	if (is_under_light(objects, obj, &light_ray))
		return (calculate_angle(&light_ray, *obj, inter));
	return (0);
}

void	calculate_color(t_env* env, t_point* inter, t_object** obj,
			t_color* clr)
{
	t_light*	lights;
	double		angle;

	lights = env->lights;
	while (lights != NULL)
	{
		angle = 0.0;
		if (lights->light_color != NULL)
			angle = lights->light_color(obj, inter, env->objects,
						    lights);
		clr->r = clr->r +
			 (lights->rgb.r * (*obj)->material.diffuse.r) * angle;
		clr->g = clr->g +
			 (lights->rgb.g * (*obj)->material.diffuse.g) * angle;
		clr->b = clr->b +
			 (lights->rgb.b * (*obj)->material.diffuse.b) * angle;
		lights = lights->next;
	}
}
