#include "libgraph.h"

void	draw_update(t_mlx *data)
{
	mlx_put_image_to_window(data->mlx,data->window, data->img->img, 0, 0);
}
