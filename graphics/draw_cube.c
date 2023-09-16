#include "libgraph.h"

static void	st_connect(t_mlx *data, t_vector stt, t_vector end,
			t_vector (*pers) (t_constants *, const t_vector));

void	draw_cube(t_mlx *data, t_vector stt, t_vector end,
		t_vector (*pers) (t_constants *, const t_vector))
{
	int	depth;

	depth = end.z;
	end.z = stt.z;
	draw_plane(data, stt, end, pers);
	end.z = depth;
	st_connect(data, stt, end, pers);
	stt.z = depth;
	draw_plane(data, stt, end, pers);
	draw_update(data);
}

static void	st_connect(t_mlx *data, t_vector stt, t_vector end,
			t_vector (*pers) (t_constants *, const t_vector))
{
	t_vector	vec;
	t_vector	wec;
	t_constants	*mtx;

	mtx = data->mtx;
	vec = end;
	wec = stt;
	wec.z = end.z;
	vec.z = stt.z;
	draw_line(data, pers(mtx, stt), pers(mtx, wec));
	draw_line(data, pers(mtx, end), pers(mtx, vec));
	wec.x = end.x;
	stt.x = end.x;
	end.y = stt.y;
	vec.y = stt.y;
	draw_line(data, pers(mtx, stt), pers(mtx, wec));
	draw_line(data, pers(mtx, end), pers(mtx, vec));
}
