#include "libgraph.h"

void	draw_square(t_mlx *data, t_vector topl, t_vector botr, int fill)
{
	t_vector	botl;
	t_vector	topr;

	botl.x = topl.x;
	botl.y = botr.y;
	botl.color = botr.color;
	topr.x = botr.x;
	topr.y = topl.y;
	topr.color = topl.color;
	draw_line(data, topl, topr);
	draw_line(data, topr, botr);
	draw_line(data, botr, botl);
	draw_line(data, botl, topl);
	if (fill >= 0)
		draw_fill(data, topl, botr, fill);
	draw_update(data);
}
