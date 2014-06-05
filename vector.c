#include <math.h>

#include "libid/lib.h"
#include "vector.h"

#include <stdio.h>

void	prod_vector(t_vector* a, t_vector* b, t_vector* c)
{
	c->x = a->y * b->z - a->z * b->y;
	c->y = a->z * b->x - a->x * b->z;
	c->z = a->x * b->y - a->y * b->x;
}

void	get_vector(t_point* a, t_point* b, t_vector* v)
{
	v->x = b->x - a->x;
	v->y = b->y - a->y;
	v->z = b->z - a->z;
}

double	norme(t_vector* v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

void	normalize(t_vector* v)
{
	double	norme_v;

	norme_v = norme(v);
	v->x = v->x / norme_v;
	v->y = v->y / norme_v;
	v->z = v->z / norme_v;
}

double	dot_vector(t_vector* v1, t_vector* v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}
