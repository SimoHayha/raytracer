#include <math.h>

#include "libid/lib.h"
#include "vector.h"
#include "object.h"
#include "reflection.h"

void	get_refracted_ray(t_ray* ray, t_object* obj, t_ray* new_ray)
{
	double		teta_two;
	double		dot_prod;
	t_vector	tmp;

	new_ray->distance = 20000;
	mult_vector(&ray->dest, &new_ray->origin, ray->distance);
	add_vector(&new_ray->origin, &ray->origin, &new_ray->origin);
	get_normal(obj, &new_ray->origin, &new_ray->dest);
	dot_prod = dot_vector(&ray->dest, &new_ray->dest);
	teta_two = asin(sin(acos(dot_prod)) / obj->material.refract);
	mult_vector(&new_ray->dest, &new_ray->dest, cos(teta_two) + dot_prod / obj->material.refract);
	div_vector(&ray->dest, &tmp, obj->material.refract);
	sub_vector(&tmp, &new_ray->dest, &new_ray->dest);
}
