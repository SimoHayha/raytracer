#ifndef __MATRICE_H__
#define __MATRICE_H__

#include "point.h"

#define M_LEN_X	4
#define M_LEN_Y	4

enum
{
	ROTATION_X,
	ROTATION_Y,
	ROTATION_Z
};

typedef struct	s_matrice
{
	t_point	a;
	t_point	b;
	t_point	c;
	t_point	p;
}	t_matrice;

typedef t_matrice	MATRICE;

void	m3_inverse(double mr[9], double ma[9]);
void	m3_identity(double mat[9]);
float	m3_det(double mat[9]);

void	m4_struct_to_mat(t_matrice* matrice, double mat4[16]);
void	m4_checkcolumn(int* t, int* dst, int i);
void	m4_submat(double mr[16], double mb[9], int i, int j);
float	m4_det(double mr[16]);
int	_m4_inverse(double mr[16], double ma[16]);
int	m4_inverse(t_matrice* mat1, t_matrice* mat2);
void	m3_mult_matcol(double m3[9], double mc3[3]);

void	m4_rotation_x(t_point* p, double angle);
void	m4_rotation_y(t_point* p, double angle);
void	m4_rotation_z(t_point* p, double angle);

void	m4_mult_matcol(double m1[16], double m2[4]);

#endif
