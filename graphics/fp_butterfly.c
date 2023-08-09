#include "libgraph.h"
#include "formulas.h"
#include "colors.h"
#include "unistd.h"

void	fp_butterfly(t_mlx *data, t_vector center)
{
	double	i;

	i = 0.0000;
	while (i < 12 * M_PI)
	{
		fp_putpixel(data, BUTTERFLY_X(i) + center.x,
			BUTTERFLY_Y(i) + center.y, RED);
		mlx_put_image_to_window(data->mlx,
			data->window, data->img->img, 0, 0);
		usleep(1000 * 50);
		i += 0.01;
	}
}
