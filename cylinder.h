#ifndef __CYLINDER_H__
#define __CYLINDER_H__

#include "libid/lib.h"

typedef struct	s_cylinder
{
	t_vector	dir;
	float		radius;
}	t_cylinder;

typedef struct	s_env	t_env;

int	new_cylinder(t_env* env, char** input, int nb_words);

#endif
