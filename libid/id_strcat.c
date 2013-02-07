#include "lib.h"

char*	id_strcat(char* s1, char* s2)
{
	int	i;
	int	size;

	i = 0;
	if (s2 == NULL)
		return (s1);
	else if (s1 == NULL)
		return (NULL);
	size = id_strlen(s1);
	while (s2[i] != 0)
	{
		s1[i + size] = s2[i];
		i = i + 1;
	}
	s1[i + size] = 0;
	return (s1);
}

char*	id_strncat(char* s1, char* s2, int n)
{
	int	i;
	int	size;

	i = 0;
	if (s2 == NULL)
		return (s1);
	else if (s1 == NULL)
		return (NULL);
	size = id_strlen(s1);
	while (s2[i] != 0 && i < n)
	{
		s1[i + size] = s2[i];
		i = i + 1;
	}
	return (s1);
}
