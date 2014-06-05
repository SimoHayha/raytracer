#ifndef __RAYTRACER_H__
#define __RAYTRACER_H__

typedef struct	s_thread_data	t_thread_data;
typedef struct	s_thread_pixel	t_thread_pixel;

#define PI		(4 * atan(1))
#define MAX_DEPTH	6

int	raytracer(t_thread_data* thread, double x, double y,
		  t_thread_pixel* pixel);

#endif
