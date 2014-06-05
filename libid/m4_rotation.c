#include <math.h>

#include "lib.h"

static void		do_rotation(double matrice[16], t_point* p)
{
	double	point[4];

	point[0] = p->x;
	point[1] = p->y;
	point[2] = p->z;
	point[3] = p->homogeneous;
	matrice[3] = point[0];
	matrice[7] = point[1];
	matrice[11] = point[2];
	matrice[15] = point[3];
	m4_mult_matcol(matrice, point);
	p->x = point[0];
	p->y = point[1];
	p->z = point[2];
	p->homogeneous = point[3];
}

void		m4_rotation_x(t_point* p, double angle)
{
	double	matrice[16];

	id_memset(&matrice, 0, sizeof(matrice));
	matrice[0] = 1;
	matrice[5] = cos(angle);
	matrice[6] = -sin(angle);
	matrice[9] = sin(angle);
	matrice[10] = cos(angle);
	do_rotation(matrice, p);
}

void		m4_rotation_y(t_point* p, double angle)
{
	double	matrice[16];

	id_memset(&matrice, 0, sizeof(matrice));
	matrice[5] = 1;
	matrice[0] = cos(angle);
	matrice[3] = sin(angle);
	matrice[8] = -sin(angle);
	matrice[10] = cos(angle);
	do_rotation(matrice, p);
}

void		m4_rotation_z(t_point* p, double angle)
{
	double	matrice[16];

	id_memset(&matrice, 0, sizeof(matrice));
	matrice[10] = 1;
	matrice[0] = cos(angle);
	matrice[1] = -sin(angle);
	matrice[4] = sin(angle);
	matrice[5] = cos(angle);
	do_rotation(matrice, p);
}
