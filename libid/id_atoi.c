#include "lib.h"

int	id_atoi(char* str)
{
	int	minus;
	int	nb;

	nb = 0;
	minus = 1;
	if (str == NULL)
		return (0);
	while ((*str < '0' || *str > '9') && *str != 0)
	{
		if (*str == '-')
			minus = -minus;
		str = str + 1;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = 10 * nb + (*str - '0');
		str = str + 1;
	}
	return (nb * minus);
}

int	id_atoi_move(char* str, int* i)
{
	int	minus;
	int	nb;

	nb = 0;
	minus = 1;
	if (str == NULL)
		return (0);
	while ((str[*i] < '0' || str[*i] > '9') &&
		str[*i] != 0)
	{
		if (str[*i] == '-')
			minus = -minus;
		*i = *i + 1;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = 10 * nb + (str[*i] - '0');
		*i = *i + 1;
	}
	return (nb * minus);
}
