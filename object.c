#include <stdlib.h>

#include "libid/lib.h"
#include "object.h"

Object*	get_new_object(void)
{
	Object*	new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	id_memset(new, 0, sizeof(*new));
	return (new);
}

Object*	add_object(Object* list, Object* new)
{
	if (!list)
		return (new);
	new->next = list;
	return (new);
}

void	remove_all_object(Object* list)
{
	Object*	tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
