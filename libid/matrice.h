#ifndef __MATRICE_H__
#define __MATRICE_H__

#include "point.h"

#define M_LEN_X	4
#define M_LEN_Y	4

typedef struct	s_matrice
{
	t_point	a;
	t_point	b;
	t_point	c;
	t_point	p;
}	t_matrice;

typedef t_matrice	MATRICE;

typedef double		MATCOL3[3];
typedef double		MATRIX3[9];
typedef double		MATRIX4[16];

void	m3_inverse(MATRIX3 mr, MATRIX3 ma);
void	m3_identity(MATRIX3 mat);
float	m3_det(MATRIX3 mat);

void	m4_struct_to_mat(MATRICE* matrice, MATRIX4 mat4);
void	m4_checkcolumn(int* t, int* dst, int i);
void	m4_submat(MATRIX4 mr, MATRIX3 mb, int i, int j);
float	m4_det(MATRIX4 mr);
int	_m4_inverse(MATRIX4 mr, MATRIX4 ma);
int	m4_inverse(MATRICE* mat1, MATRICE* mat2);
void	m3_mult_matcol(MATRIX3 m3, MATCOL3 mc3);

#endif
