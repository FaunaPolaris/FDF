/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:35:20 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/12 17:33:10 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	st_core(t_mlx *data, char *line);
static int	st_len(char ***map);
static int	fx(int n, t_mlx *data);
static int	fy(int n, t_mlx *data);
//static int	st_gridheight(char ***grid);

int	main(int argc, char **argv)
{
	t_mlx	data;
	int		fd;
	char	*line;

	if (argc != 2 || !fp_strnstr(argv[1], ".fdf", fp_strlen(argv[1])))
		return (1);
	if (graphics_init("fdf", &data))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	line = fp_read_all(fd);
	if (!line)
		return (1);
	st_core(&data, line);
	free(line);
	close(fd);
	graphics_end(&data);
	return (0);
}

static void	st_core(t_mlx *data, char *line)
{
	char	***map;
	t_vector	vv[2];
	int		i;
	int		x;
	int		y;

	map = fp_splitsplit(line, '\n', ' ');
	i = -1;
	while (++i < st_len(map))
	{
		x = i / fp_grdlen(map[0]);
		y = i % fp_grdlen(map[0]);
		vv[0] = mtx_newv(fx(x, data), fy(y, data),
			fp_atoi(map[x][y]),
			fp_atox(fp_strchr(map[x][y], ',')));
		if (map[x][y + 1])
		{
			vv[1] = mtx_newv(fx(x, data), fy(y + 1, data),
				fp_atoi(map[x][y + 1]),
				fp_atox(fp_strchr(map[x][y + 1], ',')));
			draw_line(data, vv[0], vv[1]);
		}
		if (map[x + 1])
		{
			vv[1] = mtx_newv(fx(x + 1, data), fy(y, data),
				fp_atoi(map[x + 1][y]),
				fp_atox(fp_strchr(map[x + 1][y], ',')));
			draw_line(data, vv[0], vv[1]);
		}
	}
	usleep(10000 * 500);
}
/*
static int	st_gridheight(char ***grid)
{
	int	i;

	i = -1;
	while (grid[++i])
		;
	return (i);
}
*/
static int	fx(int n, t_mlx *data)
{
	return ((n * 20) + data->ofx);
}

static int	fy(int n, t_mlx *data)
{
	return ((n * 20) + data->ofy);
}

static int	st_len(char ***map)
{
	int	i;
	int	output;

	i = -1;
	output = 0;
	while (map[++i])
		output += fp_grdlen(map[i]);
	return (output);
}
