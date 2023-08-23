#include "libgraph.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_mlx	data;
	t_vector	*vertice;
	int	i = 0;

	if (argc != 4)
		return (1);
	if (fp_graphical_init("cube", &data))
		return (1);
	vertice = fp_rect(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	fp_isometric(vertice, 8);
	//fp_putvertice(&data, vertice, 8, 0xFF00FF);
	while (i < 50)
	{
		fp_putrect(&data, vertice);
//		fp_rotxvertice(vertice, 8, 1);
		mlx_put_image_to_window(data.mlx, data.window, data.img->img, 0, 0);
		usleep(500 * 1000);
		fp_set_all(&data, 0x000000);
		i++;
	}
	free(vertice);
	fp_graphical_end(&data);
	return (0);
}
