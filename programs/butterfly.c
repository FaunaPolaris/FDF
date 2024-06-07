#include "libgraph.h"

void		*g_mlx;
t_constants	*g_mtx;

int	main(void)
{
	t_window	*win;

	g_mlx = mlx_init();
	g_mtx = mtx_init();
	win = win_open("Formula Projection", 1320, 720);
	draw_butterfly(win, vec_center());
	mlx_destroy_display(g_mlx);
	free(g_mtx);
	free(win);
	free(g_mtx);
	return (1);
}
