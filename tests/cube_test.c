#include "libgraph.h"
#include <unistd.h>

static void	st_cube_animation(void);

int	main(int argc, char **argv)
{
	t_mlx	data;
	t_vector	*vertice;
	int	i = 0;

	if (argv[1][0] == 'A')
		st_cube_animation();
	if (argc != 4)
		return (1);
	if (fp_graphical_init("cube", &data))
		return (1);
	vertice = fp_rect(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
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

static void	st_cube_animation(void)
{
	t_mlx	data;
	int	i = 16;
	int	j = 16;
	int	k = 16;
	int	iter = 0;
	t_vector	*vertice;

	if (fp_graphical_init("cube", &data))
		return ;
	while (1)
	{
		vertice = fp_rect(i, j, k);
		fp_putrect(&data, vertice);
		mlx_put_image_to_window(data.mlx, data.window, data.img->img, 0, 0);
		usleep(50 * 1000);
		fp_set_all(&data, 0x000000);
		if (++iter < 32)
		{
			i += 8;
			k += 8;
		}
		else if (++iter < 64)
		{
			i -= 8;
			k -= 8;
		}
		else if (++iter < 96)
		{
			j += 8;
			k += 8;
		}
		else if (++iter < 128)
		{
			j -= 8;
			k -= 8;
		}
		else
			break ;
	}
}
