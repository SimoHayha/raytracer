#include <stdarg.h>
#include "lib.h"
#include "specifier_enum.h"
#include "print_fcts.h"

#ifndef NULL
#define NULL	0
#endif

void	ini_fcts_tab(function* fcts)
{
	fcts[E_NONE] = NULL;
	fcts[E_CHAR] = &spe_printchar;
	fcts[E_STR] = &spe_printstr;
	fcts[E_INT] = &spe_printnbr;
	fcts[E_PTR] = NULL;
}

int	check_specifier(const char* str, int i, t_specifier* option)
{
	int	tmp;

	tmp = i + 1;
	if (str[tmp] == 'c')
		*option = E_CHAR;
	else if (str[tmp] == 's')
		*option = E_STR;
	else if (str[tmp] == 'd')
		*option = E_INT;
	else if (str[tmp] == 'p')
		*option = E_PTR;
	else
		return (i);
	return (tmp + 1);
}

void	print_fct(function* fcts, t_specifier option, va_list* a_list)
{
	if (option == E_NONE)
		return ;
	fcts[option](a_list);
}

void	id_print(const char* str, ...)
{
	int		i;
	va_list		a_list;
	function	fcts[E_SIZE];
	t_specifier	option;

	i = 0;
	if (!str)
		return ;
	va_start(a_list, str);
	ini_fcts_tab(fcts);
	option = E_NONE;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i = check_specifier(str, i, &option);
			print_fct(fcts, option, &a_list);
		}
		id_printchar(str[i]);
		i = i + 1;
	}
}
