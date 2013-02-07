#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

void	set_to_send(int* size_to_send, char** new_buf, t_buf* buf)
{
	if (buf->len >= SIZE_BUFFER)
	{
		*size_to_send = SIZE_BUFFER;
		*new_buf = id_strdup(buf->buf + SIZE_BUFFER);
		if (*new_buf == NULL)
			*new_buf = (char*)-1;
	}
	else
	{
		*size_to_send = buf->len;
		*new_buf = NULL;
	}
}

int	send_in_fd(t_buf* buf, int fd)
{
	int	ret;
	char*	new_buf;
	int	size_to_send;

	set_to_send(&size_to_send, &new_buf, buf);
	if (new_buf == (char*)-1)
		return (id_perror("Send in fd: new buf"));
	ret = send(fd, buf->buf, size_to_send, 0);
	if (ret != size_to_send)
		return (id_perror("SEND"));
	free(buf->buf);
	buf->buf = new_buf;
	return (0);
}

int	send_fct(t_buffer* buffer, int sock_fd)
{
	if (send_in_fd(buffer->buf + buffer->cur_buf, sock_fd))
		return (-1);
	buffer->cur_buf = buffer->cur_buf + 1;
	if (buffer->cur_buf == buffer->nb_buf)
		free_buf(buffer);
	return (0);
}
