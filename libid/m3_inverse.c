#include "lib.h"
#include "matrice.h"

float	m3_det(double mat[9])
{
	float	det;

	det = mat[0] * (mat[4] * mat[8] - mat[7] * mat[5]) -
	      mat[1] * (mat[3] * mat[8] - mat[6] * mat[5]) +
	      mat[2] * (mat[3] * mat[7] - mat[6] * mat[4]);
	return (det);
}

void	m3_identity(double mat[9])
{
	int	i;

	i = 0;
	while (i < 9)
	{
		mat[i] = 0;
		i = i + 1;
	}
	mat[0] = 1;
	mat[4] = 1;
	mat[8] = 1;
}

void	m3_inverse(double mr[9], double ma[9])
{
	float	det;

	det = m3_det(ma);
	if (det == 0)
	{
		m3_identity(ma);
		return ;
	}
	mr[0] = (ma[4] * ma[8] - ma[5] * ma[7]) / det;
	mr[1] = -(ma[1] * ma[8] - ma[7] * ma[2]) / det;
	mr[2] = (ma[1] * ma[5] - ma[4] * ma[2]) / det;
	mr[3] = -(ma[3] * ma[8] - ma[5] * ma[6]) / det;
	mr[4] = (ma[0] * ma[8] - ma[6] * ma[2]) / det;
	mr[5] = -(ma[0] * ma[5] - ma[3] * ma[2]) / det;
	mr[6] = (ma[3] * ma[7] - ma[6] * ma[4]) / det;
	mr[7] = -(ma[0] * ma[7] - ma[6] * ma[1]) / det;
	mr[8] = (ma[0] * ma[4] - ma[1] * ma[3]) / det;
}
