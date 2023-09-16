#include "libgraph.h"

void	draw_plane(t_window *win, t_vector stt, t_vector end,
		t_vector (*prjct) (const t_vector))
{
	t_vector	vec;
	t_vector	wec;

	vec = end;
	vec.y = stt.y;
	wec = stt;
	wec.y = end.y;
	draw_line(win, prjct(vec), prjct(end));
	draw_line(win, prjct(vec), prjct(end));
	draw_line(win, prjct(end), prjct(wec));
	draw_line(win, prjct(wec), prjct(stt));
	draw_line(win, prjct(stt), prjct(vec));
}
