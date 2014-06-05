#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "color.h"

typedef struct	s_material
{
	t_color	specular;
	t_color	diffuse;
	t_color	ambiant;
	t_color	selfillum;
	double	shininess;
	double	shine_strength;
	double	transmit;
	int	reflect;
	double	refract;
}	t_material;

#endif
