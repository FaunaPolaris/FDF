#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdfdata	*data;
	t_mlx		mlx;

	data = (t_fdfdata *)fp_calloc(1, sizeof(t_fdfdata));
	if (argc != 2)
	{
		fp_printf("incorrect number of arguments");
		return (1);
	}
	data = fdf_read_map(argv[1]);
	if (data->max_x == 0 && data->max_y == 0)
		return (1);
	if (fp_graphical_init("draw_test", &mlx))
	{
		fp_printf("error on graphical initialization");
		return (1);
	}
	data->mlx = &mlx;
	for (int i = 0; i < data->max_y; i++)
	{
			fp_putvertice(data->mlx, &data->grid[data->max_x - 1][i].vertice,
					1, 0x0000FF);
	}
	fdf_draw_map(data->grid, data, fp_isometric);
	usleep(10000 * 500);
	fp_erase_frame(data->grid, data->max_x);
	fp_graphical_end(data->mlx);
	free(data);
	return (0);
}
