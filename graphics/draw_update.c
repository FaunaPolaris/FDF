#include "libgraph.h"

void	draw_update(t_window *win)
{
	if (!win->exists)
		return ;
	mlx_put_image_to_window(g_mlx, win->window, win->img, 0, 0);
}
