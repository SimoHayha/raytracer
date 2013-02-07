#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "vector.h"
#include "object.h"

typedef struct	s_camera
{
	Vector3D	origin;
	Vector3D	sight;
}	t_camera;

typedef struct	s_camera	Camera;

int	add_camera(Object** objects, char** line, int nb_word);

#endif
