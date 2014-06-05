#include <math.h>
#include <stdio.h>

#include "math_function.h"
#include "libid/lib.h"
#include "cylinder.h"
#include "vector.h"
#include "object.h"
#include "sphere.h"
#include "object.h"

int	set_result(double t0, double t1, t_ray* ray)
{
	int	result;

	result = 0;
	if (t0 > EPSILON && t0 < ray->distance)
	{
		ray->distance = t0;
		result = 1;
	}
	if (t1 > EPSILON && t1 < ray->distance)
	{
		ray->distance = t1;
		result = 1;
	}
	return (result);
}

int	get_delta_sphere(t_ray* ray, t_ray* new_ray, t_sphere* sphere)
{
	double		d[3];

	d[0] = id_pow(ray->dest.x, 2) + id_pow(ray->dest.y, 2) +
	       id_pow(ray->dest.z, 2);
	d[1] = 2 * (ray->dest.x * new_ray->origin.x +
		    ray->dest.y * new_ray->origin.y +
		    ray->dest.z * new_ray->origin.z);
	d[2] = id_pow(new_ray->origin.x, 2) +
	       id_pow(new_ray->origin.y, 2) +
	       id_pow(new_ray->origin.z, 2) -
	       id_pow(sphere->radius, 2);
	d[2] = id_pow(d[1], 2) - 4 * d[0] * d[2];
	if (d[2] < EPSILON)
		return (0);
	return (set_result((-d[1] - sqrt(d[2])) / (2 * d[0]),
			   (-d[1] + sqrt(d[2])) / (2 * d[0]),
			   ray));
}

int	get_cylinder_value(t_vector* ao, t_vector* ab, t_cylinder* cyl,
			   t_ray** rays)
{
	double		d[3];
	t_vector	ao_x_ab;
	t_vector	v_x_ab;

	prod_vector(ao, ab, &ao_x_ab);
	prod_vector(&(*rays[1]).dest, ab, &v_x_ab);
	d[0] = dot_vector(&v_x_ab, &v_x_ab);
	d[1] = 2 * dot_vector(&v_x_ab, &ao_x_ab);
	d[2] = dot_vector(&ao_x_ab, &ao_x_ab) -
	       id_pow(cyl->radius, 2) * dot_vector(ab, ab);
	d[2] = id_pow(d[1], 2) - 4 * d[0] * d[2];
	if (d[2] < EPSILON)
		return (0);
	return (set_result((-d[1] - sqrt(d[2])) / (2 * d[0]),
			   (-d[1] + sqrt(d[2])) / (2 * d[0]),
			   &(*rays[0])));
}

int	get_delta_cylinder(t_ray* ray, t_ray* new_ray, t_cylinder* cyl)
{
	t_ray*		rays[2];
	t_vector	ao;
	t_vector	ab;
	t_vector	origin;
	t_vector	end;

	id_memset(&origin, 0, sizeof(origin));
	origin.y = -20000;
	id_memset(&end, 0, sizeof(end));
	end.y = 20000;
	sub_vector(&end, &origin, &ab);
	sub_vector(&new_ray->origin, &origin, &ao);
	rays[0] = ray;
	rays[1] = new_ray;
	return (get_cylinder_value(&ao, &ab, cyl, rays));
}
