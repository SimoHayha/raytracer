#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "libid/lib.h"
#include "matrix.h"
#include "vector.h"

void	matrix_mult(double* m1, t_vector* v, t_vector* r, char is_vec)
{
	r->x = m1[0] * v->x + m1[1] * v->y + m1[2] * v->z;
	r->y = m1[4] * v->x + m1[5] * v->y + m1[6] * v->z;
	r->z = m1[8] * v->x + m1[9] * v->y + m1[10] * v->z;
	if (!is_vec)
	{
		r->x = r->x + m1[3];
		r->y = r->y + m1[7];
		r->z = r->z + m1[11];
	}
}

void	align_z(t_transformation* t, t_vector* v)
{
	t->rotation_align_z[0] = v->x / sqrt(id_pow(v->x, 2) + id_pow(v->y, 2));
	t->rotation_align_z[1] = v->y / sqrt(id_pow(v->x, 2) + id_pow(v->y, 2));
	t->rotation_align_z[4] = -v->y / sqrt(id_pow(v->x, 2) + id_pow(v->y, 2));
	t->rotation_align_z[5] = v->x / sqrt(id_pow(v->x, 2) + id_pow(v->y, 2));
	t->is_rotation_align_z = 1;
}

void	get_rotation_all_matrix(t_transformation* t, t_vector* u, t_vector* v)
{
	t_vector	axis;
	double		angle;
	double		c;
	double		s;

	id_memset(&t->rotation_all, 0, sizeof(t->rotation_all));
	angle = acos(dot_vector(v, u));
	c = cos(angle);
	s = sin(angle);
	prod_vector(u, v, &axis);
	t->rotation_all[0] = id_pow(axis.x, 2) + (1 - id_pow(axis.x, 2)) * c;
	t->rotation_all[1] = axis.x * axis.y * (1 - c) - axis.z * s;
	t->rotation_all[2] = axis.x * axis.z * (1 - c) + axis.y * s;
	t->rotation_all[4] = axis.x * axis.y * (1 - c) + axis.z * s;
	t->rotation_all[5] = id_pow(axis.y, 2) + (1 - id_pow(axis.y, 2)) * c;
	t->rotation_all[6] = axis.y * axis.z * (1 - c) - axis.x * s;
	t->rotation_all[8] = axis.x * axis.z * (1 - c) - axis.y * s;
	t->rotation_all[9] = axis.y * axis.z * (1 - c) + axis.x * s;
	t->rotation_all[10] = id_pow(axis.z, 2) + (1 - id_pow(axis.z, 2)) * c;
	t->is_rotation_all = 1;
}

void	get_translation_matrix(t_transformation* t, t_vector* o, t_vector* w)
{
	id_memset(&t->move, 0, sizeof(t->move));
	t->move[0] = 1;
	t->move[5] = 1;
	t->move[10] = 1;
	t->move[15] = 1;
	t->move[3] = -(o->x - w->x);
	t->move[7] = -(o->y - w->y);
	t->move[11] = -(o->z - w->z);
	t->is_move = 1;
}
