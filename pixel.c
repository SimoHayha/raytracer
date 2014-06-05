#include <stdlib.h>

#include "libid/lib.h"
#include "pixel.h"

t_pixel*	get_pixel(void)
{
	t_pixel*	new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	id_memset(new, 0, sizeof(*new));
	return (new);
}

t_pixel*	add_pixel(t_pixel* list, t_pixel* new)
{
	if (!list)
		return (new);
	new->next = list;
	list = new;
	return (list);
}

void		remove_pixel_list(t_pixel* list)
{
	t_pixel*	tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
