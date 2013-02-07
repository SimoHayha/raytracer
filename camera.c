#include <stdlib.h>

#include "libid/lib.h"
#include "camera.h"

int	add_camera(Object** objects, char** line, int nb_word)
{
	Object*	new;
	Camera*	camera;

	if (nb_word - 1 != CAMERA_ARG)
		return (1);
	new = get_new_object();
	camera = malloc(sizeof(*camera));
	if (!new || !camera)
	{
		free(new);
		free(camera);
		return (2);
	}
	id_print("Adding camera\n");
	camera->origin.x = (double)atof(line[1]);
	camera->origin.y = (double)atof(line[2]);
	camera->origin.z = (double)atof(line[3]);
	camera->sight.x = (double)atof(line[4]);
	camera->sight.y = (double)atof(line[5]);
	camera->sight.z = (double)atof(line[6]);
	new->object = camera;
	new->type = OBJ_CAMERA;
	new->intersect = NULL;
	*objects = add_object(*objects, new);
	return (0);
}
