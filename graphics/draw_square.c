#include "libgraph.h"

void	draw_square(t_window *win, t_vector topl, t_vector botr, int fill)
{
	t_vector	botl;
	t_vector	topr;

	botl.x = topl.x;
	botl.y = botr.y;
	botl.color = botr.color;
	topr.x = botr.x;
	topr.y = topl.y;
	topr.color = topl.color;
	draw_line(win, topl, topr);
	draw_line(win, topr, botr);
	draw_line(win, botr, botl);
	draw_line(win, botl, topl);
	if (fill >= 0)
		draw_fill(win, topl, botr, fill);
	draw_update(win);
}
