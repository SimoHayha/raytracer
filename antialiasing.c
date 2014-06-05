#include "libid/lib.h"
#include "thread.h"
#include "raytracer.h"
#include "env.h"

void		make_avg(t_thread_pixel* cut_pixel, t_thread_pixel* pixel)
{
	int	i;
	double	avg[3];

	i = 0;
	id_memset(avg, 0, sizeof(avg));
	while (i < ANTIALIASING * ANTIALIASING)
	{
		avg[0] = avg[0] + cut_pixel[i].r;
		avg[1] = avg[1] + cut_pixel[i].g;
		avg[2] = avg[2] + cut_pixel[i].b;
		i = i + 1;
	}
	pixel->r = avg[0] / (ANTIALIASING * ANTIALIASING);
	pixel->g = avg[1] / (ANTIALIASING * ANTIALIASING);
	pixel->b = avg[2] / (ANTIALIASING * ANTIALIASING);
}

void	antialiasing(t_thread_data* my_data, double real_x,
		     double real_y, double offset)
{
	t_thread_pixel	pixel[ANTIALIASING * ANTIALIASING];
	int		i;
	int		j;
	double		pixel_x;
	double		pixel_y;

	i = 0;
	pixel_x = real_x;
	pixel_y = real_y;
	while (i < ANTIALIASING * ANTIALIASING)
	{
		raytracer(my_data, pixel_x, pixel_y, &pixel[i]);
		pixel_y = pixel_y + offset;
		i = i + 1;
		if (i % (ANTIALIASING) == 0)
		{
			pixel_y = real_y;
			pixel_x = pixel_x + offset;
		}
	}
	j = (int)(real_x * my_data->env->height + real_y);
	make_avg(pixel, &my_data->pixels[j]);
	my_data->pixels[j].pixel_x = real_x;
	my_data->pixels[j].pixel_y = real_y;
}
