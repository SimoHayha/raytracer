#include "lib.h"

void	mult_vector(t_vector* v, t_vector* dest, double n)
{
	dest->x = v->x * n;
	dest->y = v->y * n;
	dest->z = v->z * n;
}

void	add_vector(t_vector* u, t_vector* v, t_vector* dest)
{
	dest->x = u->x + v->x;
	dest->y = u->y + v->y;
	dest->z = u->z + v->z;
}

void	sub_vector(t_vector* u, t_vector* v, t_vector* dest)
{
	dest->x = u->x - v->x;
	dest->y = u->y - v->y;
	dest->z = u->z - v->z;
}
