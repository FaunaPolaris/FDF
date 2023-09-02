#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdfdata	*data;
	t_mlx		mlx;
	int	fd;

	data = (t_fdfdata *)fp_calloc(1, sizeof(t_fdfdata));
	if (argc != 2)
	{
		fp_printf("incorrect number of arguments");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	data = fdf_check_map(fd, argv[1]);
	close(fd);
	data->grid = fp_new_frame(data->max_x, data->max_y);
	fd = open(argv[1], O_RDONLY);
	fdf_apply_depth(fd, data);
	if (fp_graphical_init("draw_test", &mlx))
	{
		fp_printf("error on graphical initialization");
		return (1);
	}
	data->mlx = &mlx;
	fdf_draw_map(data->grid, data, fp_isometric);
	usleep(10000 * 500);
	fp_erase_frame(data->grid, data->max_x);
	fp_graphical_end(data->mlx);
	free(data);
	return (0);
}
