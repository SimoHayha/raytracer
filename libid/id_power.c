#include "lib.h"

double	id_pow(double x, int y)
{
	if (y > 0)
		return (x * id_pow(x, y - 1));
	else
	{
		if (y < 0)
			return (0);
		else
			return (1);
	}
}
