/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:56:47 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/08 15:40:16 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	st_free(char *line, char **grid);
static void	st_find_size(int fd, t_fdfdata *data);
static void	st_find_specs(int fd, t_fdfdata *data);
static void	st_color_height(char *specs, t_fdfdata *data, int x, int y);

t_fdfdata	*fdf_read_map(char *name)
{
	t_fdfdata	*output;
	int			fd;

	output = (t_fdfdata *)fp_calloc(1, sizeof(t_fdfdata));
	if (!(fp_strnstr(name, ".fdf", fp_strlen(name))))
		return (output);
	fd = open(name, O_RDONLY);
	st_find_size(fd, output);
	close(fd);
	output->grid = fp_new_frame(output->max_x, output->max_y);
	fd = open(name, O_RDONLY);
	st_find_specs(fd, output);
	close(fd);
	return (output);
}

static void	st_find_size(int fd, t_fdfdata *data)
{
	char	*line;
	char	**grid;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (st_free(line, NULL));
		grid = fp_split(line, ' ');
		if (!grid)
			return (st_free(line, grid));
		line[fp_strlen(line) - 1] = '\0';
		if (fp_gridlen(grid) > data->max_x)
			data->max_x = fp_gridlen(grid);
		data->max_y++;
		if (fp_griditer(grid, fp_strcuto))
			data->max_z = fp_griditer(grid, fp_strcuto);
		st_free(line, grid);
	}
}

static void	st_find_specs(int fd, t_fdfdata *data)
{
	char	*line;
	char	**posix;
	int		i;
	int		j;

	i = -1;
	while (++i < data->max_y)
	{
		line = get_next_line(fd);
		if (!line)
			return (st_free(line, NULL));
		posix = fp_split(line, ' ');
		if (!posix)
			return (st_free(line, posix));
		line[fp_strlen(line) - 1] = '\0';
		j = -1;
		while (++j < data->max_x && j < fp_gridlen(posix))
		{
			if (fp_strchr(posix[j], ','))
				st_color_height(posix[j], data, j, i);
			else
				data->grid[j][i].vertice.z = fp_atoi(posix[j]);
		}
		st_free(line, posix);
	}
}

static void	st_color_height(char *specs, t_fdfdata *data, int x, int y)
{
	char	**split;

	split = fp_split(specs, ',');
	if (!split[0] || !split[1])
		return ;
	data->grid[x][y].color = fp_atox(split[1]);
	data->grid[x][y].vertice.z = fp_atoi(split[0]);
	st_free(NULL, split);
}

static void	st_free(char *line, char **grid)
{
	int	i;

	i = -1;
	if (line)
		free(line);
	if (grid)
	{
		while (grid[++i])
			free(grid[i]);
		free(grid);
	}
}
