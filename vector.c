#include <math.h>
#include <stdlib.h>

#include "libid/lib.h"
#include "vector.h"

void		vector_normalize(Vector3D* v)
{
	double	id;

	id =  1 / sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x = v->x * id;
	v->y = v->y * id;
	v->z = v->z * id;
}

double		vector_dot(Vector3D* v1, Vector3D* v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

Vector3D*	vector_copy(Vector3D* v)
{
	Vector3D*	copy;

	copy = malloc(sizeof(*copy));
	if (!copy)
		return (NULL);
	return (id_memcpy(copy, v, sizeof(*copy)));
}

Vector3D*	vector_sub(Vector3D* v1, Vector3D* v2)
{
	Vector3D*	sub;

	sub = malloc(sizeof(*sub));
	if (!sub)
		return (NULL);
	sub->x = v1->x - v2->x;
	sub->y = v1->y - v2->y;
	sub->z = v1->z - v2->z;
	return (sub);
}
