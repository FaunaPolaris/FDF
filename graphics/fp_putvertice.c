#include "libgraph.h"

void	fp_putvertice(t_mlx *data, t_vector *vertice, int quantity, int color)
{
	int	i;

	i = 0;
	fp_printf("(%i, %i, %i)\n", (int)vertice->x, (int)vertice->y, (int)vertice->z);
	while (i < quantity)
	{
		fp_putpixel(data,vertice[i].x + (WIDTH / 2),
					vertice[i].y + (HEIGHT / 2),
					color);
		i++;
	}
	mlx_put_image_to_window(data->mlx,
			data->window, data->img->img, 0, 0);
}
