#include <stdlib.h>
#include <math.h>

#include "libid/lib.h"
#include "sphere.h"

int	sphere_intersect(void* object, Ray* ray, double* coef)
{
	int		result;
	Sphere*		sphere;
	Vector3D*	dist;
	double		b;
	double		d;
	double		t0;
	double		t1;

	sphere = (Sphere*)object;
	dist = vector_copy(&sphere->position);
	if (!dist)
		return (0);
	vector_sub(dist, &ray->origin);
	b = vector_dot(&ray->destination, dist);
	d = b * b - vector_dot(dist, dist) + sphere->radius * sphere->radius;
	if (d < 0)
		return (0);
	t0 = b - sqrt(d);
	t1 = b + sqrt(d);
	result = 0;
	if (t0 > 0.1 && t0 < *coef)
	{
		*coef = t0;
		result = 1;
	}
	if (t1 > 0.1 && t1 < *coef)
	{
		*coef = t1;
		result = 1;
	}
	return (result);
}

int	add_sphere(Object** objects, char** line, int nb_word)
{
	Object*	new;
	Sphere*	sphere;

	if (nb_word - 1 != SPHERE_ARG)
		return (2);
	new = get_new_object();
	sphere= malloc(sizeof(*sphere));
	if (!new || !sphere)
	{
		free(new);
		free(sphere);
		return (1);
	}
	id_print("Adding sphere\n");
	new->red = id_atoi(line[1]);
	new->green = id_atoi(line[2]);
	new->blue = id_atoi(line[3]);
	sphere->position.x = (double)atof(line[4]);
	sphere->position.y = (double)atof(line[5]);
	sphere->position.z = (double)atof(line[6]);
	sphere->radius = (double)atof(line[7]);
	new->object = sphere;
	new->type = OBJ_SPHERE;
	new->intersect = &sphere_intersect;
	*objects = add_object(*objects, new);
	return (0);
}
