#include <stdarg.h>
#include <unistd.h>
#include "lib.h"
#include "print_fcts.h"

void	spe_printchar(va_list* a_list)
{
	char	tmp;

	tmp = va_arg(*a_list, int);
	write(1, &tmp, 1);
}

void	spe_printstr(va_list* a_list)
{
	char*	str;

	str = va_arg(*a_list, char*);
	if (str == NULL)
		return ;
	write(1, str, id_strlen(str));
}

void	spe_printnbr(va_list* a_list)
{
	int	n;
	int	div;

	n = va_arg(*a_list, int);
	div = 1;
	while (n / div >= 10 || n / div <= -10)
		div = div * 10;
	if (n < 0)
		id_printchar('-');
	while (div > 0)
	{
		if (n > 0)
			id_printchar((n / div) % 10 + '0');
		else
			id_printchar((n / div) % 10 * -1 + '0');
		div = div / 10;
	}
}
