#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct	s_queue
{
	void*		value;
	struct s_queue*	next;
}	t_queue;

typedef t_queue	QUEUE;

QUEUE*	get_queue(void);
QUEUE*	push_front(QUEUE* queue, QUEUE* add);
QUEUE*	pop_front(QUEUE* queue);
void	clean_queue(QUEUE* queue);

#endif
