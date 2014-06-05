#include <stdlib.h>
#include <math.h>

#include "math_function.h"
#include "plane_utils.h"
#include "translation.h"
#include "libid/lib.h"
#include "vector.h"
#include "object.h"
#include "plane.h"
#include "env.h"

void	color_plane(t_ray* ray, t_vector* inter, t_object* obj, t_color* clr)
{
	double		angle;
	t_vector	light;

	sub_vector(&ray->origin, inter, &light);
	normalize(&light);
	angle = dot_vector(&((t_plane*)obj->object)->dir, &light);
	if (angle < 0.0)
		angle = -angle;
	clr->r = obj->material.diffuse.r * AMBIANT_RED * angle;
	clr->g = obj->material.diffuse.g * AMBIANT_GREEN * angle;
	clr->b = obj->material.diffuse.b * AMBIANT_BLUE * angle;
}

int	cut_plane(t_object* obj, t_ray* ray)
{
	double		t;
	t_plane*	plane;

	plane = (t_plane*)obj->object;
	t = (dot_vector(&plane->dir, &obj->pos) -
	     dot_vector(&ray->origin, &plane->dir)) /
	    dot_vector(&ray->dest, &plane->dir);
	if (t < EPSILON || t > ray->distance)
		return (0);
	ray->distance = t;
	return (1);
}

void	fill_plane_transformation(t_object* new_obj)
{
	new_obj->transform.is_move = 0;
	new_obj->transform.is_rotation_x = 0;
	new_obj->transform.is_rotation_y = 0;
	new_obj->transform.is_rotation_z = 0;
	new_obj->transform.is_rotation_all = 0;
	new_obj->transform.is_rotation_align_z = 0;
}

void	fill_plane(t_env* env, t_object* new_obj, t_plane* new, char** input)
{
	new_obj->pos.homogeneous = 1;
	new->dir.homogeneous = 0;
	normalize(&new->dir);
	new_obj->color = &color_plane;
	new_obj->intersect = &cut_plane;
	new_obj->material.diffuse.r = (double)id_atoi(input[1]) / 255.0f;
	new_obj->material.diffuse.g = (double)id_atoi(input[2]) / 255.0f;
	new_obj->material.diffuse.b = (double)id_atoi(input[3]) / 255.0f;
	new_obj->pos.x = atof(input[4]);
	new_obj->pos.y = atof(input[5]);
	new_obj->pos.z = atof(input[6]);
	new->dir.x = atof(input[7]);
	new->dir.y = atof(input[8]);
	new->dir.z = atof(input[9]);
	new_obj->object = new;
	new_obj->obj_type = E_PLANE;
	new_obj->next = env->objects;
	env->objects = new_obj;
	fill_plane_transformation(new_obj);
}

int	new_plane(t_env* env, char** input, int nb_words)
{
	t_plane*	new;
	t_object*	new_obj;

	new = NULL;
	new_obj = NULL;
	if (nb_words < 10)
	{
		id_wordtabfree(input);
		return (id_error("new_plane args"));
	}
	new = malloc(sizeof(*new));
	new_obj = malloc(sizeof(*new_obj));
	if (new == NULL || new_obj == NULL)
	{
		free(new);
		free(new_obj);
		id_wordtabfree(input);
		return (id_error("new_plane"));
	}
	fill_plane(env, new_obj, new, input);
	optional_input_plane(new_obj, input, nb_words);
	id_wordtabfree(input);
	make_object_translation(new_obj);
	return (0);
}
