#include "libgraph.h"

void	fp_putvertice(t_mlx *data, t_vector *vertice, int quantity, int color)
{
	int	i;
	int	x_per;
	int	y_per;

	i = 0;
	while (i < quantity)
	{
		x_per = vertice[i].x / vertice[i].z;
		y_per = vertice[i].y / vertice[i].z;
		fp_putpixel(data, (x_per + 1) * 0.5 * WIDTH,
				((1 - y_per) * 0.5 * HEIGHT),
				color);
		i++;
	}
	mlx_put_image_to_window(data->mlx,
			data->window, data->img->img, 0, 0);
}
