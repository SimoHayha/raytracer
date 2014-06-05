#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "color.h"

typedef struct	s_point	t_point;
typedef struct	s_point	t_vector;

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	dest;
	double		distance;
	double		refract;
	char		in_obj;
}	t_ray;

double	norme(t_vector* v);
void	prod_vector(t_vector* a, t_vector* b, t_vector* c);
void	get_vector(t_point* a, t_point* b, t_vector* v);
void	normalize(t_vector* v);
double	dot_vector(t_vector* v1, t_vector* v2);

#endif
