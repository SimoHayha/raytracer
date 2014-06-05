#ifndef __PIXEL_H__
#define __PIXEL_H__

#include "libid/lib.h"

typedef struct	s_pixel
{
	t_point*	point;
	int		r;
	int		g;
	int		b;
	struct s_pixel*	next;
}	t_pixel;

t_pixel*	get_pixel(void);
t_pixel*	add_pixel(t_pixel* list, t_pixel* add);
void		remove_pixel_list(t_pixel* list);

#endif
