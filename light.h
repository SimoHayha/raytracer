#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "color.h"
#include "type.h"
#include "libid/point.h"

typedef struct	s_env	t_env;

typedef double	get_light_color(t_object**, t_point*, t_object*, t_light*);

typedef struct	s_light
{
	double			angle;
	t_color			rgb;
	t_point			pos;
	t_vector		dir;
	t_type			type;
	get_light_color*	light_color;
	struct s_light*		next;
}	t_light;

int	new_light(t_env* env, char** line, int nb_words);

#endif
