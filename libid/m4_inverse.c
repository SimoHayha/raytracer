#include "lib.h"
#include "matrice.h"

void	m4_struct_to_mat(MATRICE* matrice, MATRIX4 mat4)
{
	mat4[0] = matrice->a.x;
	mat4[1] = matrice->a.y;
	mat4[2] = matrice->a.z;
	mat4[3] = matrice->a.homogeneous;
	mat4[4] = matrice->b.x;
	mat4[5] = matrice->b.y;
	mat4[6] = matrice->b.z;
	mat4[7] = matrice->b.homogeneous;
	mat4[8] = matrice->c.x;
	mat4[9] = matrice->c.y;
	mat4[10] = matrice->c.z;
	mat4[11] = matrice->c.homogeneous;
	mat4[12] = matrice->p.x;
	mat4[13] = matrice->p.y;
	mat4[14] = matrice->p.z;
	mat4[15] = matrice->p.homogeneous;
}

void	m4_checkcolumn(int* t, int* dst, int i)
{
	if (*t < i)
		*dst = *t;
	else
	{
		if (*t > i)
			*dst = *t - 1;
	}
}

void	m4_submat(MATRIX4 mr, MATRIX3 mb, int i, int j)
{
	int	ti;
	int	tj;
	int	idst;
	int	jdst;

	ti = 0;
	while (ti < 4)
	{
		m4_checkcolumn(&ti, &idst, i);
		tj = 0;
		while (tj < 4)
		{
			m4_checkcolumn(&tj, &jdst, j);
			if (ti != i && tj != j)
				mb[idst * 3 + jdst] = mr[ti * 4 + tj];
			tj = tj + 1;
		}
		ti = ti + 1;
	}
}

float	m4_det(MATRIX4 mr)
{
	float	det;
	float	result;
	float	i;
	MATRIX3	msub3;
	int	n;

	n = 0;
	while (n < 4)
	{
		m4_submat(mr, msub3, 0, n);
		det = m3_det(msub3);
		result = result + mr[n] * det * i;
		n = n + 1;
		i = i * -1;
	}
	return (result);
}

int	_m4_inverse(MATRIX4 mr, MATRIX4 ma)
{
	float	mdet;
	MATRIX3	mtemp;
	int	i;
	int	j;
	int	sign;

	mdet = m4_det(ma);
	if (mdet == 0)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			sign = 1 - ((i + j) % 2 ) * 2;
			m4_submat(ma, mtemp, i, j);
			mr[i + j * 4] = (m3_det(mtemp) * sign) / mdet;
		}
	}
	return (1);
}
