#ifndef __SPHERE_H__
#define __SPHERE_H__

typedef struct	s_point	t_point;

typedef struct	s_sphere
{
	float			radius;
}	t_sphere;

typedef struct	s_env	t_env;

int	new_sphere(t_env* env, char** input, int nb_words);

#endif
