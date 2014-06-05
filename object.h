#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "type.h"
#include "material.h"
#include "matrix.h"

typedef struct	s_ray			t_ray;
typedef struct	s_plane			t_plane;
typedef struct	s_point			t_point;
typedef struct	s_point			t_vector;
typedef struct	s_object		t_object;

typedef int	inter(t_object*, t_ray*);
typedef void	get_color(t_ray*, t_point*, t_object*, t_color*);
typedef void	get_obj_normal(t_object*, t_vector*);

typedef struct	s_object
{
	t_point			pos;
	t_type			obj_type;
	t_material		material;
	get_color*		color;
	void*			object;
	inter*			intersect;
	t_transformation	transform;
	struct s_object*	next;
}	t_object;

void	get_normal(t_object* obj, t_point* inter, t_vector* normal, t_ray* ray);

#endif
