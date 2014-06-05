#include "translation.h"
#include "libid/lib.h"
#include "cylinder.h"
#include "object.h"
#include "vector.h"
#include "plane.h"

void	get_normal(t_object* obj, t_point* inter, t_vector* normal, t_ray* ray)
{
	t_cylinder*	cylinder;
	t_ray		new_ray;
	t_point		new_inter;
	t_point		new_pos;

	if (obj->obj_type == E_SPHERE)
		get_vector(&obj->pos, inter, normal);
	else if (obj->obj_type == E_PLANE)
		copy_vector(normal, &((t_plane*)obj->object)->dir);
	else if (obj->obj_type == E_CYLINDER)
	{
		cylinder = (t_cylinder*)obj->object;
		get_translation_vect(&obj->transform, &ray->dest,
				     &new_ray.dest);
		get_transformed_point(&obj->transform, &ray->origin,
				      &new_ray.origin);
		mult_vector(&new_ray.dest, &new_inter, ray->distance);
		add_vector(&new_ray.origin, &new_inter, &new_inter);
		new_pos.x = new_inter.x + cylinder->radius;
		new_pos.y = new_inter.y + cylinder->radius;
		new_pos.z = 0;
		get_vector(&new_pos, &new_inter, normal);
	}
	normalize(normal);
}
