#include "libgraph.h"

void	fp_putvertice(t_mlx *data, t_vector *vertice, int quantity, int color)
{
	int	i;
	double	scale_x;
	double	scale_y;
	double	ratio;

	ratio = (double)WIDTH / (double)HEIGHT;
	scale_x = WIDTH * ratio / (vertice[2].x - vertice[0].x);
	scale_y = HEIGHT * ratio / (vertice[2].y - vertice[0].y);
	i = 0;
	while (i < quantity)
	{
		fp_putpixel(data, scale_x * vertice[i].x + (WIDTH / 2),
					scale_y * vertice[i].y + (HEIGHT / 2),
					color);
		i++;
	}
	mlx_put_image_to_window(data->mlx,
			data->window, data->img->img, 0, 0);
}
