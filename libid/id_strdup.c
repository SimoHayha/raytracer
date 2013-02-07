#include <stdlib.h>
#include "lib.h"

char*	id_strdup(char* str)
{
	char*	ret;
	int	len;

	if (str == NULL)
		return (str);
	len = id_strlen(str);
	ret = calloc(len + 1, sizeof(*ret));
	if (ret == NULL)
		return (0);
	ret = id_strcpy(ret, str);
	return (ret);
}

char*	id_strndup(char* str, unsigned int size)
{
	char*	ret;

	if (str == NULL)
		return (NULL);
	ret = calloc(size + 1, sizeof(*ret));
	if (ret == NULL)
		return (0);
	ret = id_strncpy(ret, str, size);
	return (ret);
}
