#ifndef __RAYTRACER_UTILS_H__
#define __RAYTRACER_UTILS_H__

typedef struct	s_color		t_color;
typedef struct	s_ray		t_ray;

void	apply_coef(t_color* clr, t_object* obj);
int	apply_color(t_color* clr);
void	init_raytrace(t_ray* ray, t_vector* inter, t_env* env,
		      t_vector* real_inter);
int	init_color_depth(t_color* clr, int depth);

#endif
