#include "libgraph.h"

void	draw_point(t_window *win, t_vector vertice, int color)
{
	draw_pixel(win,vertice.x, vertice.y, color);
	draw_update(win);
}
