#ifndef __ANTIALIASING_H__
#define __ANTIALIASING_H__

typedef struct	s_thread_data	t_thread_data;

void	antialiasing(t_thread_data* my_data, double real_x,
		     double real_y, double offset);

#endif
