#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "ray.h"

enum
{
	OBJ_CAMERA,
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
};

#define CAMERA_ARG	6
#define SPHERE_ARG	7
#define PLANE_ARG	9
#define CYLINDER_ARG	10

typedef int	intersect(void* object, Ray* ray, double* coef);

typedef struct	s_object
{
	char			type;
	void*			object;
	intersect*		intersect;
	int			red;
	int			green;
	int			blue;
	struct s_object*	next;
}	t_object;

typedef struct	s_object	Object;

Object*	get_new_object(void);
Object*	add_object(Object* list, Object* new);
void	remove_all_object(Object* list);

#endif
