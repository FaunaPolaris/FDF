/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:56:47 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/01 19:10:30 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	st_free(char *line, char **grid);
static void	st_zero(t_fdfdata *output);
static void	st_find_color(t_fdfdata *data, char **grid);
static char	**st_find_max(t_fdfdata *data, char *line);

t_fdfdata	*fdf_read_map(int fd, char *name)
{
	t_fdfdata	*output;
	char	*line;
	char	**grid;

	output = (t_fdfdata *)fp_calloc(1, sizeof(t_fdfdata));
	st_zero(output);
	if (!(fp_strnstr(name, ".fdf", fp_strlen(name))))
		return (output);
	line = fp_read_all(fd);
	if (!line)
	{
		free(line);
		return(output);
	}
	grid = st_find_max(output, line);
	if (!grid)
	{
		st_free(line, grid);
		return (output);
	}
	output->grid = fp_new_frame(output->max_x, output->max_y);
	st_find_color(output, grid);
	st_free(line, grid);
	return (output);
}
static void	st_find_color(t_fdfdata *data, char **grid)
{
	int		i;
	int		j;
	char	**split;

	i = -1;
	while (++i < data->max_y)
	{
		j = -1;
		while (++j < data->max_x && j < fp_gridlen(grid))
		{
			if (fp_strchr(grid[j], ','))
			{
				split = fp_split(grid[j], ',');
				if (!split || !split[1])
					return ;
				data->grid[i][j].color = (int)fp_atox(split[1]);
				data->grid[i][j].vertice.z = fp_atoi(split[0]);
				st_free(NULL, split);
			}
			else
				data->grid[j][i].vertice.z = fp_atoi(grid[j]);
		}
	}
}
static char	**st_find_max(t_fdfdata *output, char *line)
{
	size_t		i;
	char	**grid;

	i = -1;
	while (line[++i] != '\n' && line[i])
	{
		if (line[i] != ' ')
			output->max_x++;
	}
	output->max_x++;
	i = -1;
	while (++i < fp_strlen(line))
	{
		if (line[i] == '\n')
			output->max_y++;
	}
	fp_strsub(line, '\n', ' ');
	grid = fp_split(line, ' ');
	if (!grid)
		return (NULL);
	output->max_z = fp_griditer(grid, fp_strcuto);
	return (grid);
}

static void	st_zero(t_fdfdata *output)
{
	output->max_x = 0;
	output->max_y = 0;
	output->max_z = 0;
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
