#include "libgraph.h"

void	draw_plane(t_mlx *data, t_vector start, t_vector end,
		t_vector (*pers) (const t_vector))
{
	t_vector	etemp;
	t_vector	stemp;

	etemp = end;
	etemp.y = start.y;
	stemp = start;
	stemp.y = end.y;
	draw_line(data, pers(etemp), pers(end));
	draw_line(data, pers(etemp), pers(end));
	draw_line(data, pers(end), pers(stemp));
	draw_line(data, pers(stemp), pers(start));
	draw_line(data, pers(start), pers(etemp));
}
