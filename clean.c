#include <stdlib.h>
#include "cylinder.h"
#include "matrix.h"
#include "object.h"
#include "sphere.h"
#include "light.h"
#include "plane.h"
#include "clean.h"
#include "env.h"

void	clean(t_env* env)
{
	void*	next;

	while (env->objects != NULL)
	{
		next = env->objects->next;
		free(env->objects->object);
		free(env->objects);
		env->objects = (t_object*)next;
	}
	while (env->lights != NULL)
	{
		next = env->lights->next;
		free(env->lights);
		env->lights = (t_light*)next;
	}
	free(env->pixels);
}
