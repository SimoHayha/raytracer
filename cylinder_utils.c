#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "libid/lib.h"
#include "object.h"

void	optional_input_cylinder(t_object* new_obj, char** input, int nb_words)
{
	if (nb_words > 11)
		new_obj->material.reflect = id_atoi(input[11]);
	else
		new_obj->material.reflect = 0;
	if (nb_words > 12)
		new_obj->material.refract = atof(input[12]);
	else
		new_obj->material.refract = 0.0;
}
