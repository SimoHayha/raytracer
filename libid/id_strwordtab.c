#include <stdlib.h>

#include "lib.h"

int	id_strlen_charset(char* str, char* charset)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != 0 && !is_in_charset(str[i], charset))
		i = i + 1;
	return (i);
}

int	count_word(char* str, char* charset)
{
	char	last;
	int	nbword;

	nbword = 0;
	last = charset[0];
	while (*str != 0)
	{
		if (is_in_charset(last, charset) &&
		    !is_in_charset(*str, charset))
			nbword = nbword + 1;
		last = *str;
		str = str + 1;
	}
	return (nbword);
}

int	copy_all_word(char** ret, char* str, char* charset, int i)
{
	int	nbword;
	int	len;
	char	last;

	nbword = 0;
	last = charset[0];
	while (str[i] != 0)
	{
		if (is_in_charset(last, charset) &&
		    !is_in_charset(str[i], charset))
		{
			len = id_strlen_charset(str + i, charset);
			ret[nbword] = id_strndup(str + i, len);
			if (!ret[nbword])
				return (1);
			nbword = nbword + 1;
			last = str[i];
			i = i + len - 1;
		}
		last = str[i];
		i = i + 1;
	}
	return (0);
}

void	id_word_tab_free(char** val)
{
	int	i;

	i = 0;
	if (val == NULL)
		return ;
	while (val[i] != 0)
	{
		free(val[i]);
		i = i + 1;
	}
	free(val);
}

char**	id_strwordtab(char* str, char* charset, int* nbword)
{
	char**	ret;

	if (str == NULL)
		return (NULL);
	*nbword = count_word(str, charset);
	ret = calloc(*nbword + 1, sizeof(*ret));
	if (ret == NULL)
		return (0);
	if (copy_all_word(ret, str, charset, 0))
	{
		id_word_tab_free(ret);
		return (0);
	}
	return (ret);
}
