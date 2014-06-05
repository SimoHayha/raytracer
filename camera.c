#include <math.h>
#include <stdlib.h>

#include "libid/lib.h"
#include "translation.h"
#include "rotation.h"
#include "camera.h"
#include "vector.h"
#include "matrix.h"
#include "env.h"

void	get_up_vector(t_camera* cam)
{
	if (cam->dir.y == 0)
		cam->up_vector.x = 0;
	else
		cam->up_vector.x = 1 / sqrt(id_pow(-cam->dir.x / cam->dir.y, 2)
					    + 1);
	cam->up_vector.y = sqrt(1 - id_pow(cam->up_vector.x, 2));
	cam->up_vector.z = 0;
}

void	fill(t_env* env, char** input)
{
	env->camera.pos.x = atof(input[1]);
	env->camera.pos.y = atof(input[2]);
	env->camera.pos.z = atof(input[3]);
	env->camera.pos.homogeneous = 1;
	env->camera.dir.x = atof(input[4]);
	env->camera.dir.y = atof(input[5]);
	env->camera.dir.z = atof(input[6]);
	env->camera.dir.homogeneous = 0;
	env->camera.viewplane_dist = norme(&env->camera.dir);
	env->camera.viewplane_height = VIEWPLANE_WIDTH * env->height /
				       env->width;
	env->camera.viewplane_width = VIEWPLANE_WIDTH;
	env->camera.x_indent = env->camera.viewplane_width / env->width;
	env->camera.y_indent = env->camera.viewplane_height / env->height;
}

void	get_translation_camera(t_camera* camera)
{
	t_vector	o;

	id_memset(&o, 0, sizeof(o));
	get_translation_matrix(&camera->transform, &camera->pos, &o);
}

void	get_rotation_camera(t_camera* camera)
{
	t_vector	axis;

	axis.x = 0;
	axis.y = 0;
	axis.z = 1;
	get_rotation_all_matrix(&camera->transform, &camera->dir, &axis);
}

int	fill_camera(t_env* env, char** input, int nb_words)
{
	if (nb_words < 7)
	{
		id_wordtabfree(input);
		return (id_error("fill_camera"));
	}
	fill(env, input);
	normalize(&env->camera.dir);
	get_up_vector(&env->camera);
	prod_vector(&env->camera.dir, &env->camera.up_vector,
		    &env->camera.right_vector);
	id_wordtabfree(input);
	env->camera.transform.is_move = 0;
	env->camera.transform.is_rotation_x = 0;
	env->camera.transform.is_rotation_y = 0;
	env->camera.transform.is_rotation_z = 0;
	env->camera.transform.is_rotation_all = 0;
	env->camera.transform.is_rotation_align_z = 0;
	get_translation_camera(&env->camera);
	get_rotation_camera(&env->camera);
	return (0);
}
