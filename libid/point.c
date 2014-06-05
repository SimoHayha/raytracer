#include "lib.h"

void	div_vector(t_vector* v, t_vector* dest, double n)
{
	dest->x = v->x / n;
	dest->y = v->y / n;
	dest->z = v->z / n;
}

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
	if (u != NULL)
	{
		dest->x = u->x - v->x;
		dest->y = u->y - v->y;
		dest->z = u->z - v->z;
	}
	else
	{
		dest->x = -v->x;
		dest->y = -v->y;
		dest->z = -v->z;
	}
}

void	copy_vector(t_vector* ret, t_vector* v)
{
	id_memcpy(ret, v, sizeof(*ret));
}
