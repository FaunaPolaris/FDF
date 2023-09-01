#include "fdf.h"

int	fdf_draw_map(t_wireframe **grid, t_fdfdata *data,
		t_vector (*fp) (t_vector *, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < data->max_x)
	{
		j = 0;
		while (j < data->max_y)
		{
			fp_putline(data->mlx->mlx, fp(&grid[i][j].vertice, 1),
					fp(&grid[i][j].xplus->vertice, 1));
			j++;
		}
		i++;
	}
	return (1);
}
