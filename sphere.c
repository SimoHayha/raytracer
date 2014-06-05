#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "libid/lib.h"
#include "object.h"
#include "sphere.h"
#include "vector.h"
#include "translation.h"
#include "math_function.h"
#include "env.h"

void	color_sphere(t_ray* ray, t_vector* inter, t_object* obj, t_color* clr)
{
	t_vector	normal;
	double		angle;
	t_vector	light;

	get_normal(obj, inter, &normal, ray);
	sub_vector(NULL, &ray->dest, &light);
	angle = dot_vector(&normal, &light);
	if (angle < 0.0)
		angle = 0.0;
	clr->r = obj->material.diffuse.r * AMBIANT_RED * angle;
	clr->g = obj->material.diffuse.g * AMBIANT_GREEN * angle;
	clr->b = obj->material.diffuse.b * AMBIANT_BLUE * angle;
}

int	cut_sphere(t_object* obj, t_ray* ray)
{
	t_sphere*	sphere;
	t_ray		new_ray;

	sphere = (t_sphere*)obj->object;
	get_transformed_point(&obj->transform, &ray->origin, &new_ray.origin);
	get_translation_vect(&obj->transform, &ray->dest, &new_ray.dest);
	return (get_delta_sphere(ray, &new_ray, sphere));
}

static void	optional_input(t_object* new_obj, char** input, int nb_words)
{
	if (nb_words > 8)
		new_obj->material.reflect = id_atoi(input[8]);
	else
		new_obj->material.reflect = 0;
	if (nb_words > 9)
		new_obj->material.refract = atof(input[9]);
	else
		new_obj->material.refract = 0.0;
}

void	fill_sphere(t_env* env, t_object* new_obj, t_sphere* new, char** input)
{
	new->radius = atof(input[7]);
	new_obj->material.diffuse.r = (double)id_atoi(input[1]) / 255.0f;
	new_obj->material.diffuse.g = (double)id_atoi(input[2]) / 255.0f;
	new_obj->material.diffuse.b = (double)id_atoi(input[3]) / 255.0f;
	new_obj->pos.x = atof(input[4]);
	new_obj->pos.y = atof(input[5]);
	new_obj->pos.z = atof(input[6]);
	new_obj->pos.homogeneous = 1;
	new_obj->intersect = &cut_sphere;
	new_obj->color = &color_sphere;
	new_obj->object = new;
	new_obj->obj_type = E_SPHERE;
	new_obj->next = env->objects;
	env->objects = new_obj;
	new_obj->transform.is_move = 0;
	new_obj->transform.is_rotation_x = 0;
	new_obj->transform.is_rotation_y = 0;
	new_obj->transform.is_rotation_z = 0;
	new_obj->transform.is_rotation_all = 0;
	new_obj->transform.is_rotation_align_z = 0;
}

int	new_sphere(t_env* env, char** input, int nb_words)
{
	t_sphere*	new;
	t_object*	new_obj;

	new = NULL;
	new_obj = NULL;
	if (nb_words < 8)
	{
		id_wordtabfree(input);
		return (id_error("new_sphere args"));
	}
	new = malloc(sizeof(*new));
	new_obj = malloc(sizeof(*new_obj));
	if (new == NULL || new_obj == NULL)
	{
		free(new);
		free(new_obj);
		id_wordtabfree(input);
		return (id_error("new_sphere"));
	}
	fill_sphere(env, new_obj, new, input);
	optional_input(new_obj, input, nb_words);
	id_wordtabfree(input);
	make_object_translation(new_obj);
	return (0);
}
