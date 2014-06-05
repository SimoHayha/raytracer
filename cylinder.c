#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "translation.h"
#include "libid/lib.h"
#include "cylinder.h"
#include "object.h"
#include "vector.h"
#include "rotation.h"
#include "matrix.h"
#include "math_function.h"
#include "cylinder_utils.h"
#include "env.h"

void	color_cylinder(t_ray* ray, t_vector* inter, t_object* obj, t_color* clr)
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

int	cut_cylinder(t_object* obj, t_ray* ray)
{
	t_cylinder*	cyl;
	t_ray		new_ray;

	cyl = (t_cylinder*)obj->object;
	get_translation_vect(&obj->transform, &ray->dest, &new_ray.dest);
	get_transformed_point(&obj->transform, &ray->origin, &new_ray.origin);
	return (get_delta_cylinder(ray, &new_ray, cyl));
}

void	make_cylinder_rotation(t_vector* dir, t_transformation* t, t_vector* origin)
{
	t_vector	y_axis;
	t_vector	o;
	t_vector	ret;

	id_memset(&y_axis, 0, sizeof(y_axis));
	id_memset(&o, 0, sizeof(o));
	y_axis.y = 1;
	get_rotation_all_matrix(t, dir, &y_axis);
	get_translation_matrix(t, origin, &o);
	get_translation_vect(t, dir, &ret);
}

void	fill_cylinder(t_env* env, t_object* new_obj, t_cylinder* new,
		      char** input)
{
	new->dir.x = atof(input[7]);
	new->dir.y = atof(input[8]);
	new->dir.z = atof(input[9]);
	new->dir.homogeneous = 0;
	new->radius = atof(input[10]);
	new_obj->intersect = &cut_cylinder;
	new_obj->pos.x = atof(input[4]);
	new_obj->pos.y = atof(input[5]);
	new_obj->pos.z = atof(input[6]);
	new_obj->pos.homogeneous = 1;
	new_obj->color = &color_cylinder;
	new_obj->material.diffuse.r = (double)id_atoi(input[1]) / 255.0f;
	new_obj->material.diffuse.g = (double)id_atoi(input[2]) / 255.0f;
	new_obj->material.diffuse.b = (double)id_atoi(input[3]) / 255.0f;
	new_obj->object = new;
	new_obj->obj_type = E_CYLINDER;
	new_obj->next = env->objects;
	env->objects = new_obj;
	new_obj->transform.is_move = 0;
	new_obj->transform.is_rotation_x = 0;
	new_obj->transform.is_rotation_y = 0;
	new_obj->transform.is_rotation_z = 0;
	new_obj->transform.is_rotation_align_z = 0;
	normalize(&new->dir);
	make_cylinder_rotation(&new->dir, &new_obj->transform, &new_obj->pos);
}

int	new_cylinder(t_env* env, char** input, int nb_words)
{
	t_cylinder*	new;
	t_object*	new_obj;

	new = NULL;
	new_obj = NULL;
	if (nb_words < 11)
	{
		id_wordtabfree(input);
		return (id_error("new_cylinder args"));
	}
	new = malloc(sizeof(*new));
	new_obj = malloc(sizeof(*new_obj));
	if (new == NULL || new_obj == NULL)
	{
		free(new);
		free(new_obj);
		id_wordtabfree(input);
		return (id_error("new_cylinder"));
	}
	fill_cylinder(env, new_obj, new, input);
	optional_input_cylinder(new_obj, input, nb_words);
	id_wordtabfree(input);
	return (0);
}
