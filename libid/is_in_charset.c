#include "lib.h"

void	is_in_escape(char c, char* escape, int* escape_ndx, int not)
{
	int	i;

	i = 0;
	if (not == 1)
		return ;
	while (escape[i] != 0)
	{
		if (c == escape[i])
		{
			if (*escape_ndx == -1)
				*escape_ndx = i;
			else if (c == escape[*escape_ndx])
				*escape_ndx = -1;
		}
		i = i + 1;
	}
}

int	is_in_charset(char c, char* charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (c == charset[i])
			return (1);
		i = i + 1;
	}
	return (0);
}

int	is_in_charset_except(char c, char* charset, char except)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (c != except && c == charset[i])
			return (1);
		i = i + 1;
	}
	return (0);
}
