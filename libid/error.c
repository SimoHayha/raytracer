#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "error.h"
#include "lib.h"

int	throw_error(char* error, char* user_msg, int ret, int free_msg)
{
	if (!error)
		id_printstr(ERR_ERR, 1);
	else
		id_printstr(error, 1);
	if (user_msg)
	{
		id_printstr(": ", 1);
		if (id_strcmp(user_msg, SHOW_PERROR) == 0)
			perror(NULL);
		else if (id_strcmp(user_msg, SHOW_GAIERROR) == 0)
			id_printstr((char*)gai_strerror(errno), 1);
		else
			id_printstr(user_msg, 1);
		if (free_msg)
			free(user_msg);
	}
	id_printchar('\n');
	return (ret);
}
