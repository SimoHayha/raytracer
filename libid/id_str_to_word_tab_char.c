#include <stdlib.h>

#include "lib.h"

int	is_sep_char(char c, char* charset)
{
	int	i;

	i = 0;
	while (i < id_strlen(charset))
	{
		if (c == charset[i])
			return (1);
		i = i + 1;
	}
	return (0);
}

int	count_word_char(char* str, char* charset)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && is_sep_char(str[i], charset))
			i = i + 1;
		if (str[i])
			nb = nb + 1;
		while (str[i] && !is_sep_char(str[i], charset))
			i = i + 1;
	}
	return (nb);
}

int	add_word_char(char* str, char** tab, int* i, char* charset)
{
	int	index;

	index = 0;
	while (str[index] && !is_sep_char(str[index], charset))
		index = index + 1;
	*tab = calloc(index + 1, sizeof(**tab));
	if (!*tab)
		return (1);
	*tab = id_strncpy(*tab, str, index);
	*i = *i + index;
	return (0);
}

char**	id_strwordtabchar(char* str, char* charset)
{
	int	i;
	int	nb;
	char**	tab;

	i = 0;
	nb = count_word_char(str, charset);
	tab = calloc(nb + 1, sizeof(*tab));
	if (!tab)
		return (NULL);
	nb = 0;
	while (str[i])
	{
		while (str[i] && is_sep_char(str[i], charset))
			i = i + 1;
		if (str[i])
		{
			if (add_word_char(str + i, &(tab[nb]), &i, charset))
				return (tab);
			nb = nb + 1;
		}
	}
	return (tab);
}
