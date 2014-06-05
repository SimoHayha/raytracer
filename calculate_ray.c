#include <math.h>

#include "calculate_ray.h"
#include "libid/lib.h"
#include "vector.h"
#include "camera.h"
#include "object.h"

#include <stdio.h>

void	get_point(t_camera* cam, t_point* point, double x, double y)
{
	point->x = -(cam->viewplane_width / 2) + cam->x_indent * x;
	point->y = (cam->viewplane_height / 2) - cam->y_indent * y;
	point->z = cam->viewplane_dist;
}

void	get_reflected_ray(t_ray* ray, t_object* obj, t_ray* new_ray)
{
	new_ray->distance = 20000;
	mult_vector(&ray->dest, &new_ray->origin, ray->distance);
	add_vector(&new_ray->origin, &ray->origin, &new_ray->origin);
	get_normal(obj, &new_ray->origin, &new_ray->dest, ray);
	mult_vector(&new_ray->dest, &new_ray->dest,
		    dot_vector(&ray->dest, &new_ray->dest));
	mult_vector(&new_ray->dest, &new_ray->dest, 2);
	sub_vector(&ray->dest, &new_ray->dest, &new_ray->dest);
	normalize(&new_ray->dest);
}

void	init_refraction(t_ray** rays, t_vector* normal,
			t_object* obj, t_vector* tmp)
{
	(*rays[1]).distance = 20000;
	mult_vector(&(*rays[0]).dest, &(*rays[1]).origin, (*rays[0]).distance);
	add_vector(&(*rays[1]).origin, &(*rays[0]).origin, &(*rays[1]).origin);
	get_normal(obj, &(*rays[1]).origin, normal, rays[0]);
	sub_vector(NULL, &(*rays[0]).dest, tmp);
	if ((*rays[0]).in_obj == 0)
	{
		if (obj->obj_type != E_PLANE)
			(*rays[1]).in_obj = 1;
		else
			(*rays[1]).in_obj = 0;
		(*rays[1]).refract = obj->material.refract;
	}
	else
	{
		sub_vector(NULL, normal, normal);
		(*rays[1]).in_obj = 0;
		(*rays[1]).refract = 1.0;
	}
}

void	get_refracted_ray(t_ray* ray, t_object* obj, t_ray* new_ray)
{
	t_vector	tmp;
	t_vector	normal;
	double		d[3];
	t_ray*		rays[2];

	rays[0] = ray;
	rays[1] = new_ray;
	init_refraction(rays, &normal, obj, &tmp);
	d[0] = dot_vector(&tmp, &normal);
	d[1] = ray->refract / new_ray->refract;
	d[2] = asin(d[1] * sin(acos(d[0])));
	mult_vector(&normal, &new_ray->dest, cos(d[2]) + d[1] * d[0]);
	mult_vector(&ray->dest, &tmp, d[1]);
	sub_vector(&tmp, &new_ray->dest, &new_ray->dest);
	normalize(&new_ray->dest);
}
