#ifndef __MATH_FUNCTION_H__
#define __MATH_FUNCTION_H__

#define EPSILON	0.001

typedef struct	s_ray		t_ray;
typedef struct	s_sphere	t_sphere;
typedef struct	s_cylinder	t_cylinder;
typedef struct	s_object	t_object;

typedef struct	s_object	t_object;

int	get_delta_sphere(t_ray* ray, t_ray* new_ray, t_sphere* sphere);
int	get_delta_cylinder(t_ray* ray, t_ray* new_ray, t_cylinder* cylinder);

#endif
