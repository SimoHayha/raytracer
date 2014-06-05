#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "libid/lib.h"
#include "matrix.h"

#define VIEWPLANE_WIDTH	0.30f

typedef struct	s_transformation	t_transformation;

typedef struct	s_camera
{
	t_point			pos;
	t_point			origin;
	t_vector		dir;
	t_vector		up_vector;
	t_vector		right_vector;
	double			x_indent;
	double			y_indent;
	double			viewplane_dist;
	double			viewplane_width;
	double			viewplane_height;
	t_transformation	transform;
}	t_camera;

typedef struct	s_env	t_env;

int	fill_camera(t_env* env, char** input, int nb_words);

#endif
