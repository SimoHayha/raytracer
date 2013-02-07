#include <stdlib.h>
#include "lib.h"

char*	str_sep_str(char* path, char* file_name, char* sep)
{
	char*		tmp;
	unsigned int	size;

	size = id_strlen(path) + id_strlen(file_name) + id_strlen(sep) + 1;
	tmp = calloc(size, sizeof(*tmp));
	if (tmp == NULL)
		return (NULL);
	tmp = id_strcpy(tmp, path);
	tmp = id_strcat(tmp, sep);
	tmp = id_strcat(tmp, file_name);
	return (tmp);
}

int	id_str_sep_str(char** str1, char* str2, char* sep)
{
	char*	tmp;

	tmp = str_sep_str(*str1, str2, sep);
	free(*str1);
	if (tmp == NULL && (*str1 != NULL || str2 != NULL || sep != NULL))
		return (-1);
	*str1 = tmp;
	return (0);
}

int	char_is_in(char* str, char* charset)
{
	if (str == NULL || charset == NULL)
		return (0);
	while (*str != 0)
	{
		if (is_in_charset(*str, charset))
			return (1);
		str = str + 1;
	}
	return (0);
}
