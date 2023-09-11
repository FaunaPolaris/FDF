#include "libgraph.h"
#include "formulas.h"

void	draw_butterfly(t_mlx *data, t_vector center)
{
	double	i;

	i = 0.0000;
	while (i < 12 * M_PI)
	{
		if (BUTTERFLY_X(i) > 0)
		{
			draw_pixel(data, BUTTERFLY_X(i) + center.x,
				BUTTERFLY_Y(i) + center.y,
				RED + BUTTERFLY_X(i));
		}
		else
		{
			draw_pixel(data, BUTTERFLY_X(i) + center.x,
				BUTTERFLY_Y(i) + center.y,
				RED + (BUTTERFLY_X(i) * -1));
		}
		mlx_put_image_to_window(data->mlx,
			data->window, data->img->img, 0, 0);
		usleep(1000 * 5);
		i += PRECISION;
	}
}
