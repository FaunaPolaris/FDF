#include "libgraph.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_vector	v;
	t_vector	c;

	if (argc != 3)
		return (1);
	if (fp_graphical_init("lerp", &mlx))
		return (1);
	v.x = argv[0][0];
	v.y = argv[0][2];
	v.z = argv[0][4];
	c.x = argv[1][0];
	c.y = argv[1][2];
	c.z = argv[1][4];
	v.color = 0xFF0000;
	c.color = 0x00FF00;
	fp_putline(&mlx, v, c);
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img->img,
			0, 0);
	fp_graphical_end(&mlx);
}
