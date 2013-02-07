#include <stdlib.h>

#include "buffer.h"
#include "lib.h"

int	init_buf(t_buf* buf)
{
	buf->buf = calloc(SIZE_BUFFER, sizeof(*buf));
	if (buf->buf == NULL)
		return (-1);
	buf->len = 0;
	return (0);
}

void	free_buf(t_buffer* buffer)
{
	int	i;

	i = 0;
	while (i < buffer->nb_buf)
	{
		free(buffer->buf[i].buf);
		i = i + 1;
	}
	free(buffer->buf);
	buffer->buf = NULL;
	buffer->nb_buf = 0;
}

int	add_buf(t_buffer* buffer, char* str)
{
	t_buf*		tmp;
	unsigned int	buf;

	buf = sizeof(*buffer->buf);
	tmp = realloc(buffer->buf, buf * (buffer->nb_buf + 1));
	if (tmp == NULL)
		return (-1);
	buffer->buf = tmp;
	if (buffer->nb_buf == 0)
		buffer->cur_buf = 0;
	if (fill_dup_buf(&buffer->buf[buffer->nb_buf].buf, str))
		return (-1);
	buffer->buf[buffer->nb_buf].len = id_strlen(str);
	buffer->nb_buf = buffer->nb_buf + 1;
	return (0);
}
