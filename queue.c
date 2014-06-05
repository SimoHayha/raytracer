#include <stdlib.h>

#include "libid/lib.h"
#include "queue.h"

QUEUE*	get_queue(void)
{
	QUEUE*	new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	id_memset(new, 0, sizeof(*new));
	return (new);
}

QUEUE*	push_front(QUEUE* queue, QUEUE* add)
{
	if (!queue)
		return (add);
	add->next = queue;
	return (add);
}

QUEUE*	pop_front(QUEUE* queue)
{
	QUEUE*	ret;

	if (!queue)
		return (NULL);
	ret = queue;
	queue = queue->next;
	return (ret);
}

void	clean_queue(QUEUE* queue)
{
	QUEUE*	tmp;

	while (queue)
	{
		tmp = queue->next;
		free(queue);
		queue = tmp;
	}
}
