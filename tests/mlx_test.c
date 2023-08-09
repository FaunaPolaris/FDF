#include "libgraph.h"

int	main(void)
{
	t_mlx	data;

	if (fp_graphical_init("test", &data))
		return (1);
	fp_putpixel(&data, WIDTH / 2, HEIGHT / 2, 0xffffffff);
	mlx_put_image_to_window(data.mlx, data.window, data.img->img, 0, 0);
	while (1)
		;
	fp_graphical_end(&data);
	return (0);
}
