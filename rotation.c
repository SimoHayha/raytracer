#include <math.h>

#include "libid/lib.h"
#include "matrix.h"
#include "vector.h"
#include "rotation.h"

void	fill_rotate_x(double* m, double angle)
{
	m[0] = 1;
	m[5] = cos(angle);
	m[6] = -sin(angle);
	m[9] = sin(angle);
	m[10] = cos(angle);
}

void	fill_rotate_y(double* m, double angle)
{
	m[0] = cos(angle);
	m[2] = sin(angle);
	m[5] = 1;
	m[8] = -sin(angle);
	m[10] = cos(angle);
}

void	fill_rotate_z(double* m, double angle)
{
	m[0] = cos(angle);
	m[1] = -sin(angle);
	m[4] = sin(angle);
	m[5] = cos(angle);
	m[10] = 1;
}

void	get_rotation_matrix(t_transformation* t, double angle, char rotation)
{
	if (!t)
		return ;
	if (rotation == ROTATE_X)
	{
		id_memset(&t->rotation_x, 0, sizeof(t->rotation_x));
		fill_rotate_x(t->rotation_x, angle);
		t->is_rotation_x = 1;
	}
	else if (rotation == ROTATE_Y)
	{
		id_memset(&t->rotation_y, 0, sizeof(t->rotation_y));
		fill_rotate_y(t->rotation_y, angle);
		t->is_rotation_y = 1;
	}
	else if (rotation == ROTATE_Z)
	{
		id_memset(&t->rotation_z, 0, sizeof(t->rotation_z));
		fill_rotate_z(t->rotation_z, angle);
		t->is_rotation_z = 1;
	}
}
