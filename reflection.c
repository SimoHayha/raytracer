#include "libid/lib.h"
#include "vector.h"
#include "object.h"
#include "reflection.h"

void	get_reflected_ray(t_ray* ray, t_object* obj, t_ray* new_ray)
{
	new_ray->distance = 20000;
	mult_vector(&ray->dest, &new_ray->origin, ray->distance);
	add_vector(&new_ray->origin, &ray->origin, &new_ray->origin);
	get_normal(obj, &new_ray->origin, &new_ray->dest);
	mult_vector(&new_ray->dest, &new_ray->dest,
		    dot_vector(&ray->dest, &new_ray->dest));
	mult_vector(&new_ray->dest, &new_ray->dest, 2);
	sub_vector(&ray->dest, &new_ray->dest, &new_ray->dest);
}
