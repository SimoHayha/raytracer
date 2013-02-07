#include "lib.h"

char*	id_strncpy(char* s1, char* s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] != 0 && i < n)
	{
		s1[i] = s2[i];
		i = i + 1;
	}
	s1[i] = 0;
	return (s1);
}
