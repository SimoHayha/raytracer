#include "lib.h"

char*	id_strcpy(char* s1, char* s2)
{
	int	i;

	i = 0;
	if (s2 == NULL)
		return (s1);
	else if (s1 == NULL)
		return (NULL);
	while (s2[i] != 0)
	{
		s1[i] = s2[i];
		i = i + 1;
	}
	s1[i] = 0;
	return (s1);
}
