#include <stdlib.h>
#include "lib.h"

void*	id_realloc(void* buf, unsigned int nb, unsigned int size)
{
	void*	tmp;

	tmp = realloc(buf, nb * size);
	if (tmp == NULL)
		return (buf);
	return (tmp);
}

void	skip_charset(char** str, char* charset)
{
	while (**str != 0 && is_in_charset(**str, charset))
		*str = *str + 1;
}

int	replace_value(char** str, char* new_str)
{
	if (new_str == NULL)
		return (0);
	free(*str);
	return (fill_dup_buf(str, new_str));
}

int	fill_dup_buf(char** buf, char* str)
{
	*buf = id_strdup(str);
	if (*buf == NULL && str != NULL)
		return (id_perror("Fill Dup Buf: Dup"));
	return (0);
}
