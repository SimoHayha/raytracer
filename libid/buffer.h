#ifndef __BUFFER_H__
#define __BUFFER_H__

#define SIZE_BUFFER	1024

typedef struct	s_buf
{
	int	len;
	char*	buf;
}	t_buf;

typedef struct	s_buffer
{
	t_buf*	buf;
	int	nb_buf;
	int	cur_buf;
}	t_buffer;

int	init_buf(t_buf* buf);
void	free_buf(t_buffer* buffer);
int	add_buf(t_buffer* buffer, char* str);

#endif
