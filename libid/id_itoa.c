#include <stdlib.h>

#include "lib.h"

char*	get_nbdigit(int* div, int n)
{
	char*	ret;
	int	nbdigit;

	*div = 1;
	nbdigit = 1;
	while (n / *div >= 10 || n / *div <= -10)
	{
		nbdigit = nbdigit + 1;
		*div = *div * 10;
	}
	if (n < 0)
		nbdigit = nbdigit + 1;
	ret = malloc(sizeof(ret) * (nbdigit + 1));
	return (ret);
}

char*	id_itoa(int n)
{
	char*	ret;
	int	div;
	int	nbdigit;

	ret = get_nbdigit(&div, n);
	if (ret == 0)
		return (0);
	nbdigit = 0;
	while (div > 0)
	{
		if (n < 0)
			ret[nbdigit] = '0' + ((n / div) % 10 * -1);
		else
			ret[nbdigit] = '0' + ((n / div) % 10);
		nbdigit = nbdigit + 1;
		div = div / 10;
	}
	ret[nbdigit] = 0;
	return (ret);
}

char*	get_lnbdigit(long int* div, long int n)
{
	char*		ret;
	long int	nbdigit;

	*div = 1;
	nbdigit = 1;
	while (n / *div >= 10 || n / *div <= -10)
	{
		nbdigit = nbdigit + 1;
		*div = *div * 10;
	}
	if (n < 0)
		nbdigit = nbdigit + 1;
	ret = malloc(sizeof(ret) * (nbdigit + 1));
	return (ret);
}

char*	id_ltoa(long int n)
{
	char*		ret;
	long int	div;
	long int	nbdigit;

	ret = get_lnbdigit(&div, n);
	if (ret == 0)
		return (0);
	nbdigit = 0;
	while (div > 0)
	{
		if (n < 0)
			ret[nbdigit] = '0' + ((n / div) % 10 * -1);
		else
			ret[nbdigit] = '0' + ((n / div) % 10);
		nbdigit = nbdigit + 1;
		div = div / 10;
	}
	ret[nbdigit] = 0;
	return (ret);
}
