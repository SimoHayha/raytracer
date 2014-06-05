#include "lib.h"
#include "matrice.h"

void	m3_mult_matcol(double m3[9], double mc3[3])
{
	double	ret[3];

	ret[0] = m3[0] * mc3[0] + m3[1] * mc3[1] + m3[2] * mc3[2];
	ret[1] = m3[3] * mc3[0] + m3[4] * mc3[1] + m3[5] * mc3[2];
	ret[2] = m3[6] * mc3[0] + m3[7] * mc3[1] + m3[8] * mc3[2];
	mc3[0] = ret[0];
	mc3[1] = ret[1];
	mc3[2] = ret[2];
}
