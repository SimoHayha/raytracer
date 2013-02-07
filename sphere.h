#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "vector.h"
#include "object.h"

typedef struct	s_sphere
{
	Vector3D	position;
	double		radius;
}	t_sphere;

typedef t_sphere	Sphere;

int	add_sphere(Object** objects, char** line, int nb_word);

#endif
