#include "libgraph.h"

static void	st_connect(t_mlx *data, t_vector start, t_vector end,
			t_vector (*pers) (const t_vector));

void	draw_cube(t_mlx *data, t_vector start, t_vector end,
		t_vector (*pers) (const t_vector))
{
	int	depth;

	depth = end.z;
	end.z = start.z;
	draw_plane(data, start, end, pers);
	end.z = depth;
	st_connect(data, start, end, pers);
	start.z = depth;
	draw_plane(data, start, end, pers);
	draw_update(data);
}

static void	st_connect(t_mlx *data, t_vector start, t_vector end,
			t_vector (*pers) (const t_vector))
{
	t_vector	etemp;
	t_vector	stemp;

	etemp = end;
	stemp = start;
	stemp.z = end.z;
	etemp.z = start.z;
	draw_line(data, pers(start), pers(stemp));
	draw_line(data, pers(end), pers(etemp));
	stemp.x = end.x;
	start.x = end.x;
	end.y = start.y;
	etemp.y = start.y;
	draw_line(data, pers(start), pers(stemp));
	draw_line(data, pers(end), pers(etemp));
}
