#include <stdlib.h>

void	id_wordtabfree(char** val)
{
	int	i;

	i = 0;
	if (val)
	{
		while (val[i] != 0)
		{
			free(val[i]);
			i = i + 1;
		}
		free(val);
	}
}
