#include "fdf.h"

int	fdf_new_map(int fd, t_fdfdata *data)
{
	char	*line;
	char	**grid;
	int		i;
	int		j;

	i = 0;
	while (i < data->max_y)
	{
		line = get_next_line(fd);
		grid = fp_split(line, ' ');
		if (!line || !grid)
			return (1);
		j = 0;
		while (j < data->max_x)
		{
			data->grid[j][i].color = fp_atoi(fp_strrchr(grid[j],
						'n'));
			data->grid[j][i].vertice.z =
					fp_atoi(fp_strchr(grid[j], 'n'));
			j++;
		}
		i++;
	}
	return (0);
}
