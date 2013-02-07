#include <unistd.h>
#include "lib.h"

void	id_printchar(char c)
{
	write(1, &c, 1);
}

int	id_strlen(char* str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (count);
	while (str[count] != 0)
		count = count + 1;
	return (count);
}

int	id_printstr(char* str, int fd)
{
	if (str == NULL)
		return (0);
	return (write(fd, str, id_strlen(str)));
}

int	id_printnstr(char* str, int fd, int w)
{
	int	size;

	if (str == NULL)
		return (0);
	size = id_strlen(str);
	if (w < size)
		return (write(fd, str, w));
	return (write(fd, str, id_strlen(str)));
}
