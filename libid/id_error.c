#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int	id_error(char* str)
{
	id_printstr(str, 2);
	id_printstr("\n", 2);
	return (EXIT_FAILURE);
}

int	id_perror(char* str)
{
	perror(str);
	return (EXIT_FAILURE);
}
