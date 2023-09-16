#include "libgraph.h"

t_window	*win_open(char *title, int width, int height)
{
	t_window	*win;

	win = (t_window *)fp_calloc(1, sizeof(t_window));
	if (!win)
		return (NULL);
	win->window = mlx_new_window(g_mlx, width, height, title);
	if (!win->window)
		return (NULL);
	win->img = mlx_new_image(g_mlx, width, height);
	win->addr = mlx_get_data_addr(win->img, &win->bits,
			&win->line, &win->endian);
	win->width = width;
	win->height = height;
	win->name = title;
	mlx_key_hook(win->window, win_close_sequence, win);
	win->exists = 1;
	return (win);
}

int	win_close_sequence(int keycode, void *window)
{
	if (keycode == KEY_ESC)
	{
		fp_printf("exit(1): esc key pressed\n");
		win_close(g_mlx, window);
	}
	return (1);
}

int	win_close(void *mlx, void *window)
{
	t_window	*win;

	win = (t_window *)window;
	fp_printf("closing %s\n", win->name);
	mlx_destroy_image(mlx, win->img);
	mlx_destroy_window(mlx, win->window);
	win->exists = 0;
	return (1);
}
