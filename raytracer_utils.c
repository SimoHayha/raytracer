#include "libid/lib.h"
#include "env.h"
#include "object.h"
#include "translation.h"
#include "raytracer.h"
#include "vector.h"

void	apply_coef(t_color* clr, t_object* obj)
{
	clr->r = clr->r * obj->material.diffuse.r;
	clr->g = clr->g * obj->material.diffuse.g;
	clr->b = clr->b * obj->material.diffuse.b;
}

int	apply_color(t_color* clr)
{
	if (clr->r > 255)
		clr->r = 255;
	if (clr->g > 255)
		clr->g = 255;
	if (clr->b > 255)
		clr->b = 255;
	return (1);
}

void	init_raytrace(t_ray* ray, t_vector* inter, t_env* env, t_vector* real_inter)
{
	mult_vector(&ray->dest, inter, ray->distance);
	add_vector(inter, &ray->origin, inter);
	get_transformed_point(&env->camera.transform, inter, real_inter);
}

int	init_color_depth(t_color* clr, int depth)
{
	id_memset(clr, 0, sizeof(*clr));
	if (depth > MAX_DEPTH)
		return (1);
	return (0);
}
