#include <stdlib.h>
#include "libid/lib.h"
#include "object.h"
#include "light.h"
#include "env.h"

void	fill_light(t_light* new, char** line)
{
	new->rgb.r = atof(line[1]);
	new->rgb.g = atof(line[2]);
	new->rgb.b = atof(line[3]);
	new->pos.x = atof(line[4]);
	new->pos.y = atof(line[5]);
	new->pos.z = atof(line[6]);
	new->pos.homogeneous = 1;
	if (id_strcmp("Specu", line[7]) == 0)
	{
		new->dir.x = atof(line[7]);
		new->dir.y = atof(line[8]);
		new->dir.z = atof(line[9]);
		new->angle = atof(line[10]);
		new->light_color = NULL;
		return ;
	}
	new->light_color = &light_color_diff;
}

int	new_light(t_env* env, char** line, int nb_words)
{
	t_light*	new;

	if (nb_words < 8)
	{
		id_wordtabfree(line);
		return (-1);
	}
	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		id_wordtabfree(line);
		return (-1);
	}
	fill_light(new, line);
	new->next = env->lights;
	env->lights = new;
	id_wordtabfree(line);
	return (0);
}
