#include <sys/types.h>

#include "lib.h"

void*	id_memset(void* s, int c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((char*)(s + i)) = (char)c;
		i = i + 1;
	}
	return (s);
}

void*	id_memcpy(void* dest, const void* src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((char*)(dest + i)) = *((char*)(src + i));
		i = i + 1;
	}
	return (dest);
}
