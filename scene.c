#include "libid/lib.h"
#include "env.h"
#include "object.h"
#include "camera.h"
#include "light.h"
#include "vector.h"
#include "object.h"
#include "sphere.h"
#include "plane.h"
#include "cylinder.h"
#include "scene.h"

void	replace_camera_t(t_camera* camera, t_matrice* t)
{
	t_point	translation;
	t_point	result;

	translation.x = -camera->pos.x;
	translation.y = -camera->pos.y;
	translation.z = -camera->pos.z;
	translation.homogeneous = camera->pos.homogeneous;
	get_mat_translation(t, &translation);
	mat_mult(t, &camera->pos, &result);
	camera->pos.x = result.x;
	camera->pos.y = result.y;
	camera->pos.z = result.z;
}

void	replace_obj(t_object* object, t_matrice* t)
{
	while (object)
	{
		mat_mult(t, &object->pos, &object->pos);
		object = object->next;
	}
}

void	replace_lights(t_light* lights, t_matrice* t)
{
	while (lights)
	{
		mat_mult(t, &lights->pos, &lights->pos);
		lights = lights->next;
	}
}

int	build_scene(t_env* env)
{
	t_matrice	t;

	replace_camera_t(&env->camera, &t);
	replace_obj(env->objects, &t);
	replace_lights(env->lights, &t);
	return (0);
}
