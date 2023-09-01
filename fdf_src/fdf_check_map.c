#include "fdf.h"

static void	st_free(char *line, char **grid):

t_fdfdata	*fdf_check_map(int fd, char *name)
{
	t_fdfdata	*output;
	int		temp;
	char	*line;
	char	**grid;

	output = NULL;
	output->max_y = 0;
	output->max_z = 0;
	if (!(fp_strnstr(name, ".fdf", fp_strlen(name))))
		return (output);
	while (1)
	{
		line = get_next_line(fd);
		grid = fp_split(line, ' ');
		if (!grid || !line)
			break ;
		temp = fp_griditer(grid, fp_strcuto);
		if (temp > output->max_z)
			output->max_z = temp;
		output->max_y++;
		output->max_x = fp_gridlen(grid);
		st_free(line, grid);
	}
	return (output);
}

static void	st_free(char *line, char **grid)
{
	int	i;

	i = -1;
	while (grid[++i])
		free(grid[i]);
	free(grid);
	free(line);
}
