#include "lib.h"
#include "matrice.h"

void	m4_mat_to_struct(t_matrice* mat, double mat4[16])
{
	matrice->a.x = mat4[0];
	matrice->a.y = mat4[1];
	matrice->a.z = mat4[2];
	matrice->a.homogeneous = mat4[3];
	matrice->b.x = mat4[4];
	matrice->b.y = mat4[5];
	matrice->b.z = mat4[6];
	matrice->b.homogeneous = mat4[7];
	matrice->c.x = mat4[8];
	matrice->c.y = mat4[9];
	matrice->c.z = mat4[10];
	matrice->c.homogeneous = mat4[11];
	matrice->p.x = mat4[12];
	matrice->p.y = mat4[13];
	matrice->p.z = mat4[14];
	matrice->p.homogeneous = mat4[15];
}
int	m4_inverse(t_matrice* mat1, t_matrice* mat2)
{
	double	m1[9];
	double	m2[9];
	int	ret;

	m4_struct_to_mat(mat1, m1);
	m4_struct_to_mat(mat2, m2);
	ret = _m4_inverse(m1, m2);
	m4_mat_to_struct(mat1, m1);
	m4_mat_to_struct(mat2, m2);
	return (ret);
}
