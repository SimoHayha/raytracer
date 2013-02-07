#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "libid/lib.h"
#include "camera.h"
#include "sphere.h"
#include "input.h"

int	add_by_type(Object** objects, char** line, int nb_word)
{
	char	type;

	type = line[0][0];
	if (type == 'c')
		return (add_camera(objects, line, nb_word));
	else if (type == 'S')
		return (add_sphere(objects, line, nb_word));
	id_print("Warning, object %c unknow, ignoring ...\n", type);
	return (0);
}

int	readline(Object** objects, char* buffer)
{
	char**	line;
	int	nb_word;
	char	ret;

	if (!buffer)
		return (1);
	line = id_strwordtab(buffer, " ", &nb_word);
	if (!line || nb_word <= 0)
		return (1);
	ret = add_by_type(objects, line, nb_word);
	id_wordtabfree(line);
	if (ret == 1)
		return (ret);
	return (0);
}

int	parsefile(Object** objects, char* filename)
{
	int	filefd;
	char*	buffer;

	filefd = open(filename, O_RDONLY);
	if (filefd < 0)
	{
		perror(filename);
		return (1);
	}
	buffer = id_getline(filefd);
	while (buffer)
	{
		if (readline(objects, buffer))
		{
			free(buffer);
			close(filefd);
			return (1);
		}
		free(buffer);
		buffer = id_getline(filefd);
	}
	close(filefd);
	return (0);
}
