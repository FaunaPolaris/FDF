#include "fdf.h"

static int	st_handle_keys(int keycode, void *param);
static void	st_rot(t_fdfdata *data, t_wireframe **grid, double angle,
			char axis);

int	main(int argc, char **argv)
{
	t_fdfdata	*data;
	t_mlx		mlx;

	if (argc != 2)
		return (1);
	data = fdf_read_map(argv[1]);
	if (fp_graphical_init("rotate", &mlx))
		return (1);
	data->mlx = &mlx;
	mlx_key_hook(data->mlx->window, st_handle_keys, data);
	fdf_draw_map(data->grid, data, fp_isometric);
	mlx_loop(data->mlx->mlx);
	fp_erase_frame(data->grid, data->max_x);
	fp_graphical_end(data->mlx);
	return (0);
}

static int	st_handle_keys(int keycode, void *param)
{
	t_fdfdata	*data;
	t_wireframe	**grid;

	fp_printf("handle event: %i\n", keycode);
	data = (t_fdfdata *)param;
	grid = data->grid;
	if (keycode == KEY_Q)
		st_rot(data, grid, 5, 'x');
	if (keycode == KEY_E)
		st_rot(data, grid, -5, 'x');
	if (keycode == KEY_A)
		st_rot(data, grid, 5, 'y');
	if (keycode == KEY_D)
		st_rot(data, grid, -5, 'y');
	if (keycode == KEY_W)
		st_rot(data, grid, 5, 'z');
	if (keycode == KEY_S)
		st_rot(data, grid, -5, 'z');
	return (0);
}

static void	st_rot(t_fdfdata *data, t_wireframe **grid, double angle,
			char axis)
{
	double	(*matrix)[3][3];

	matrix = mtx_rotate(axis, angle);
	for (int i = 0; i < data->max_x; i++)
	{
		for (int j = 0; j < data->max_y; j++)
			fp_applymatrix3d(&grid[i][j].vertice, matrix);
	}
	fp_printf("rotate %c\n", axis);
	fp_set_all(data->mlx, 0x000000);
	fdf_draw_map(grid, data, fp_isometric);
}
