#include "libgraph.h"

void	draw_circle(t_window *win, t_vector center, int radius, int color)
{
	int	x;
	int	y;
	double	angle;
	double	radian;

	angle = 0;
	while (angle < 320)
	{
		radian = angle / g_mtx->convert_to_radian;
		x = radius * cos(radian);
		y = radius * sin(radian);
		draw_pixel(win, x + center.x, y + center.y, color);
		angle += PRECISION;
	}
	draw_update(win);
}
