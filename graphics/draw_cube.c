#include "libgraph.h"

static void	st_connect(t_window *win, t_vector stt, t_vector end,
			t_vector (*pers) (const t_vector));

void	draw_cube(t_window *win, t_vector stt, t_vector end,
		t_vector (*pers) (const t_vector))
{
	int	depth;

	depth = end.z;
	end.z = stt.z;
	draw_plane(win, stt, end, pers);
	end.z = depth;
	st_connect(win, stt, end, pers);
	stt.z = depth;
	draw_plane(win, stt, end, pers);
	draw_update(win);
}

static void	st_connect(t_window *win, t_vector stt, t_vector end,
			t_vector (*pers) (const t_vector))
{
	t_vector	vec;
	t_vector	wec;

	vec = end;
	wec = stt;
	wec.z = end.z;
	vec.z = stt.z;
	draw_line(win, pers(stt), pers(wec));
	draw_line(win, pers(end), pers(vec));
	wec.x = end.x;
	stt.x = end.x;
	end.y = stt.y;
	vec.y = stt.y;
	draw_line(win, pers(stt), pers(wec));
	draw_line(win, pers(end), pers(vec));
}
