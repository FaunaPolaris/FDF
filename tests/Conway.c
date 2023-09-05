#include "fdf.h"
#include "time.h"

int	main(int argc, char **argv)
{
	t_wireframe	**frame;
	t_mlx		mlx;
	t_fdfdata	*data;
	int	i;
	int	j;
	int	alive;

	data = (t_fdfdata *)fp_calloc(1, sizeof(t_fdfdata));
	if (argc != 3)
		return (1);
	if (fp_graphical_init("Conway", &mlx))
		return (1);
	frame = fp_new_frame(fp_atoi(argv[1]), fp_atoi(argv[2]));
	data->mlx = &mlx;
	frame[10][10].color = 0xFF0000;
	frame[11][10].color = 0xFF0000;
	frame[10][11].color = 0xFF0000;
	frame[12][10].color = 0xFF0000;
	frame[10][12].color = 0xFF0000;
	frame[11][11].color = 0xFF0000;
	while (1)
	{
		i = -1;
		while (++i < fp_atoi(argv[1]))
		{
			j = -1;
			while (++j < fp_atoi(argv[2]))
			{
				alive = 0;
				if (frame[i][j].xplus->color == 0xFF0000
						|| frame[i][j].xmins->color == 0xFF0000
						|| frame[i][j].yplus->color == 0xFF0000
						|| frame[i][j].ymins->color == 0xFF0000)
					alive++;
				if (alive < 2)
					frame[i][j].color = 0x0000FF;
				else if (alive > 3)
					frame[i][j].color = 0x0000FF;
				else
					frame[i][j].color = 0xFF0000;
			}
		}
		fdf_draw_map(frame, data, fp_isometric);
		usleep(1000 * 50);
		fp_set_all(data->mlx, 0xFFFFFF);
	}
	fp_graphical_end(data->mlx);
	fp_erase_frame(frame, fp_atoi(argv[1]));
	return (0);
}
