#include "libgraph.h"
#include "formulas.h"

void	draw_butterfly(t_window *win, t_vector center)
{
	double	i;
	double	j;
	double	color_step;
	double	last_iter;

	last_iter = 12 * M_PI;
	color_step = PRECISION / last_iter;
	i = 0.0;
	j = 0.0;
	while (i < last_iter)
	{
		if (BUTTERFLY_X(i) > 0)
		{
			draw_pixel(win, BUTTERFLY_X(i) + center.x,
				BUTTERFLY_Y(i) + center.y,
				fp_lerpcolor(RED, BLUE, j));
		}
		else
		{
			draw_pixel(win, BUTTERFLY_X(i) + center.x,
				BUTTERFLY_Y(i) + center.y,
				fp_lerpcolor(RED, BLUE, j));
		}
		draw_update(win);
		usleep(1000 * 5);
		j += color_step;
		i += PRECISION;
	}
}
