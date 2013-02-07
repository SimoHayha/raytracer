#ifndef __RAY_H__
#define __RAY_H__

#include "vector.h"

typedef struct	s_ray
{
	Vector3D	origin;
	Vector3D	destination;
}	t_ray;

typedef t_ray	Ray;

#endif
