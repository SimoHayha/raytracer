#ifndef __REFRACTION_H__
#define __REFRACTION_H__

typedef struct	s_ray		t_ray;
typedef struct	s_object	t_object;

void	get_refracted_ray(t_ray* ray, t_object* obj, t_ray* new_ray);

#endif
