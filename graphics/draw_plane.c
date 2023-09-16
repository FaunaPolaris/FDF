#include "libgraph.h"

void	draw_plane(t_mlx *data, t_vector stt, t_vector end,
		t_vector (*prjct) (t_constants *, const t_vector))
{
	t_vector	vec;
	t_vector	wec;
	t_constants	*mtx;

	mtx = data->mtx;
	vec = end;
	vec.y = stt.y;
	wec = stt;
	wec.y = end.y;
	draw_line(data, prjct(mtx, vec), prjct(mtx, end));
	draw_line(data, prjct(mtx, vec), prjct(mtx, end));
	draw_line(data, prjct(mtx, end), prjct(mtx, wec));
	draw_line(data, prjct(mtx, wec), prjct(mtx, stt));
	draw_line(data, prjct(mtx, stt), prjct(mtx, vec));
}
