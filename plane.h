#ifndef __PLANE_H__
#define __PLANE_H__

#include "libid/lib.h"

typedef struct	s_plane
{
	t_vector	dir;
}	t_plane;

typedef struct	s_env	t_env;

int	new_plane(t_env* env, char** input, int nb_words);

#endif
