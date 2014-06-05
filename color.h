#ifndef __COLOR_H__
#define __COLOR_H__

#define AMBIANT_RED	255
#define AMBIANT_GREEN	255
#define AMBIANT_BLUE	255

typedef struct	s_env		t_env;
typedef struct	s_light		t_light;
typedef struct	s_point		t_point;
typedef struct	s_object	t_object;

typedef struct	s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

double	light_color_diff(t_object** obj, t_point* inter, t_object* objects,
			 t_light* light);
void	calculate_color(t_env* env, t_point* inter, t_object** obj,
			t_color* clr);

#endif
