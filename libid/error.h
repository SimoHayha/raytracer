#ifndef __ERROR_H__
#define __ERROR_H__

#define FATAL			-1
#define WARNING			2

#define SHOW_PERROR		"perror"
#define SHOW_GAIERROR		"gaierror"

#define ERR_ERR			"Fatal, error in error"
#define ERR_INIT_ARGS_NO_MATCH	"Fatal, bad argument count"
#define ERR_INIT_ARGS_BAD_PORT	"Fatal, bad port number"
#define ERR_INIT_GETADDRINFO	"Fatal, <getaddrinfo()> failed"
#define ERR_INIT_BINDSERVER	"Fatal, <bindserver()> failed"
#define ERR_INIT_LISTEN		"Fatal, <listen()> failed"
#define ERR_GTK_INIT		"Fatal, <gtk_init_check()> failed"

#define ERR_RUN_ADDSERVER	"Fatal, cannot add server to list"
#define ERR_RUN_SELECT		"Fatal, <select()> failed"
#define WAR_RUN_ACCEPT		"Warning, <accept()> failed"
#define WAR_ACCEPT_MAX		"Server reached maximum fd capacity"
#define WAR_RUN_ADDCLIENT	"Warning, cannot add client to list"
#define WAR_ADDCLIENT_MAL	"Malloc failed"
#define WAR_RUN_RESIZEBUFFER	"Warning, cannot resize buffer"
#define WAR_RESIZEBUFFER_REA	"Realloc failed"

int	throw_error(char* error, char* user_msg, int ret, int free_error);

#endif
