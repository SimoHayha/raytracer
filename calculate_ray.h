#ifndef __CALCULATE_RAY_H__
#define __CALCULATE_RAY_H__

typedef struct	s_ray		t_ray;
typedef struct	s_point		t_point;
typedef struct	s_camera	t_camera;
typedef struct	s_object	t_object;

void	get_point(t_camera* cam, t_point* point, double x, double y);
void	get_reflected_ray(t_ray* ray, t_object* obj, t_ray* new_ray);
void	get_refracted_ray(t_ray* ray, t_object* obj, t_ray* new_ray);

#endif
