#include "libgraph.h"

void	*g_mlx;
t_constants	*g_mtx;

int	main(void)
{
	int		x, y;
	float		check;
	t_window	*win1;
	t_window	*win2;

	g_mlx = mlx_init();
	g_mtx = mtx_init();
	win1 = win_open("Basic_test", 320, 320);
	win2 = win_open("Depth_test", 320, 320);
	for(y=0; y < 320; y++)
	{
		for(x=0; x < 320; x++)
		{
			check = perlin_nowl(x, y, 0.06, 5);
			if (check > 0.600)
				draw_pixel(win1, x, y, 0xFF0000);
			else if (check > 0.550)
				draw_pixel(win1, x, y, 0xEE0000);
			else if (check > 0.500)
				draw_pixel(win1, x, y, 0xDD0000);
			else if (check > 0.450)
				draw_pixel(win1, x, y, 0xCC0000);
			else if (check > 0.400)
				draw_pixel(win1, x, y, 0xBB0000);
			else if (check > 0.350)
				draw_pixel(win1, x, y, 0xAA0000);
			else if (check > 0.300)
				draw_pixel(win1, x, y, 0x990000);
			else if (check > 0.250)
				draw_pixel(win1, x, y, 0x880000);
			else if (check > 0.200)
				draw_pixel(win1, x, y, 0x770000);
			else if (check > 0.150)
				draw_pixel(win1, x, y, 0x660000);
			else if (check > 0.100)
				draw_pixel(win1, x, y, 0x550000);
			else if (check > 0.50)
				draw_pixel(win1, x, y, 0x440000);
			else if (check > 0.25)
				draw_pixel(win1, x, y, 0x330000);
			else
				draw_pixel(win1, x, y, 0x220000);
		}
	}
	draw_update(win1);
	for(y=0; y < 320; y++)
	{
		for(x=0; x < 320; x++)
		{
			check = perlin_nowl(x, y, 0.5, 5);
			if (check > 0.500)
				draw_pixel(win2, x, y, 0xFF00FF);
			else
				draw_pixel(win2, x, y, 0x330033);
		}
	}
	draw_update(win2);
	mlx_loop(g_mlx);
	mlx_destroy_display(g_mlx);
	free(win1);
	free(g_mtx);
	return 0;
}

