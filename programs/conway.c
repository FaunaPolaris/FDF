#include "libgraph.h"

static int	st_apply_rules(void *param);
static int	st_verify(t_wireframe cell);
static void	st_start_colors(t_wireframe **map, int chance);
static int	st_next_frame(void *wireframe);

t_constants	*g_mtx;
void		*g_mlx;

t_window	*win;

int	main(int argc, char **argv)
{
	int	width;
	int	height;
	t_wireframe	**wireframe;

	if (argc != 4)
	{
		fp_printf("invalid execution; try:\n");
		fp_printf("./conway screen_width screen_height starting_cells\n");
		return (1);
	}
	g_mlx = mlx_init();
	g_mtx = mtx_init();
	width = fp_atoi(argv[1]);
	height = fp_atoi(argv[2]);
	wireframe = fp_frmnew(width, height);
	st_start_colors(wireframe, fp_atoi(argv[3]));
	win = win_open("Conway's Game of Life", width, height);
	mlx_loop_hook(g_mlx, st_next_frame, wireframe);
	mlx_loop(g_mlx);
	fp_frmfre(wireframe);
	mlx_destroy_display(g_mlx);
	free(win);
	free(g_mtx);
	return (1);
}

static int	st_next_frame(void *wireframe)
{
	if (!win)
	{
		mlx_loop_end(g_mlx);
		return (1);
	}
	st_apply_rules(wireframe);
	return (0);
}

static int	st_apply_rules(void *param)
{
	t_wireframe	**map;
	int		x;
	int		y;
	int		live_cells;

	if (!win)
		return (0);
	map = (t_wireframe **)param;
	y = -1;
	while (++y < map[0][0].height)
	{
		x = -1;
		while (++x < map[0][0].width)
		{
			live_cells = st_verify(map[y][x]);
			if (map[y][x].color == WHITE && live_cells < 2)
				map[y][x].color = BLACK;
			else if (map[y][x].color == WHITE && live_cells > 3)
				map[y][x].color = BLACK;
			else if (map[y][x].color == BLACK && live_cells == 3)
				map[y][x].color = WHITE;
		}
	}
	y = -1;
	while (++y < map[0][0].height)
	{
		x = -1;
		while (++x < map[0][0].width)
		{
			draw_pixel(win, x, y, map[y][x].color);
		}
	}
	draw_update(win);
	usleep(100 * 500);
	return (0);
}

static int	st_verify(t_wireframe cell)
{
	int	output;

	output = 0;
	if (cell.xplus->color == WHITE)
		output++;
	if (cell.xmins->color == WHITE)
		output++;
	if (cell.yplus->color == WHITE)
		output++;
	if (cell.ymins->color == WHITE)
		output++;
	if (cell.ymins->xmins->color == WHITE)
		output++;
	if (cell.ymins->xplus->color == WHITE)
		output++;
	if (cell.yplus->xplus->color == WHITE)
		output++;
	if (cell.yplus->xmins->color == WHITE)
		output++;
	return (output);

}

static void	st_start_colors(t_wireframe **map, int chance)
{
	int	y;
	int	x;
	int	random;

	srand(time(NULL));
	y = -1;
	while (++y < map[0][0].height)
	{
		x = -1;
		while (++x < map[0][0].width)
		{
			random = rand();
			if (random % 2 == 0 && random < chance * 100000)
				map[y][x].color = WHITE;
			else
				map[y][x].color = BLACK;
		}
	}
}
