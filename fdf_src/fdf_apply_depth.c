/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_apply_depth.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:22:54 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/01 20:04:27 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	st_free(char *line, char **grid);
static void	st_get_colors(char *position, t_fdfdata *data, int i, int j);

int	fdf_apply_depth(int fd, t_fdfdata *data)
{
	char	*line;
	char	**grid;
	int		i;
	int		j;

	i = -1;
	while (++i < data->max_y - 1)
	{
		line = get_next_line(fd);
		grid = fp_split(line, ' ');
		if (!line || !grid)
			return (st_free(line, grid));
		j = -1;
		while (++j < data->max_x - 1)
		{
			if (fp_strchr(grid[j], ','))
				st_get_colors(grid[j], data, i, j);
			else
				data->grid[j][i].vertice.z = fp_atoi(grid[j]);
		}
	}
	st_free(line, grid);
	return (0);
}

static void	st_get_colors(char *position, t_fdfdata *data, int i, int j)
{
	char	**split;

	split = fp_split(position, ',');
	data->grid[j][i].color = fp_atoi(split[1]);
	data->grid[j][i].vertice.z = fp_atoi(split[0]);
	st_free(NULL, split);
}

static int	st_free(char *line, char **grid)
{
	int	i;

	i = 0;
	if (line)
		free(line);
	if (grid)
	{
		while (grid[i])
		{
			free(grid[i]);
			i++;
		}
		free(grid);
	}
	return (1);
}
