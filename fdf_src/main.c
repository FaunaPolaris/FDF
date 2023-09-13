/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:35:20 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/13 19:59:42 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	st_core(t_mlx *data, char ***map);
static t_vector	pers(t_mlx *data, t_vector v);
static void	st_draw(t_mlx *data, t_vector start, t_ivector iv, char ***map);

int	main(int argc, char **argv)
{
	t_mlx		data;
	char	***map;
	char		*line;
	int				fd;

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
	map = fp_splitsplit(line, '\n', ' ');
	data.max_x = fp_grdlen(map[0]);
	data.max_y = fp_chrcnt(line, '\n');
	st_core(&data, map);
	free(line);
	fp_grdfre3(map);
	close(fd);
	graphics_end(&data);
	return (0);
}

static void	st_core(t_mlx *data, char ***map)
{
	t_vector	v;
	t_ivector	iv;
	int		i;

	i = -1;
	while (++i < data->max_x * data->max_y)
	{
		iv.y = i / data->max_x;
		iv.x = i % data->max_x;
		v = mtx_newv(iv.y, iv.x, fp_atoi(map[iv.y][iv.x]),
				fp_atox(fp_strnxt(map[iv.y][iv.x], ',')));
		if (v.x != data->max_x - 1)
		{
			iv.z = 1;
			st_draw(data, v, iv, map);
		}
		if (v.y != data->max_y - 1)
		{
			iv.z = -1;
			st_draw(data, v, iv, map);
		}
	}
	draw_update(data);
	usleep(10000 * 500);
}

static void	st_draw(t_mlx *data, t_vector start, t_ivector iv, char ***map)
{
	t_vector	end;

	if (iv.z == 1)
		iv.x++;
	if (iv.z == -1)
		iv.y++;
	end = mtx_newv(iv.y, iv.x, fp_atoi(map[iv.y][iv.x]),
			fp_atox(fp_strnxt(map[iv.y][iv.x], ',')));
	draw_line(data, pers(data, start), pers(data, end));
	if (iv.z == 1)
		iv.x--;
	if (iv.z == -1)
		iv.y--;
}

static t_vector	pers(t_mlx *data, t_vector v)
{
	float	scalex;
	float	scaley;
	float	hypo;

	hypo = (sqrt(pow(data->max_x, 2)) + pow(data->max_y, 2));
	scalex = (((WIDTH * data->max_x)) / hypo);
	scaley = (((HEIGHT * data->max_y)) / hypo);
	if (data->max_x > data->max_y && data->max_x > 40)
		scalex /= (data->max_x / 40);
	if (scalex < scaley)
	{
		v.x *= scalex;
		v.y *= scalex;
	}
	else
	{
		v.x *= scaley;
		v.y *= scaley;
	}
	v.z *= .7;
	v = mtx_iso(v);
	v.x += (WIDTH) * .5;
	v.y += HEIGHT;
	return (v);
}
