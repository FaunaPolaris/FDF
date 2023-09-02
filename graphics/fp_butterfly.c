#include "libgraph.h"
#include "formulas.h"
#include "colors.h"
#include "unistd.h"
#include <stdio.h>

void	fp_butterfly(t_mlx *data, t_vector center)
{
	double	i;

	i = 0.0000;
	while (i < 12 * M_PI)
	{
		if (BUTTERFLY_X(i) > 0)
		{
			fp_putpixel(data, BUTTERFLY_X(i) + center.x,
				BUTTERFLY_Y(i) + center.y,
				RED + BUTTERFLY_X(i));
		}
		else
		{
		fp_putpixel(data, BUTTERFLY_X(i) + center.x,
				BUTTERFLY_Y(i) + center.y,
				RED + (BUTTERFLY_X(i) * -1));
		}
		mlx_put_image_to_window(data->mlx,
			data->window, data->img->img, 0, 0);
		printf("%f, %f \n", BUTTERFLY_X(i), BUTTERFLY_Y(i));
		usleep(1000 * 5);
		i += PRECISION;
	}
}
