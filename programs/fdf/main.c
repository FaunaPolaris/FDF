/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:35:20 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/14 16:01:16 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_map(t_mlx *data);
static void	connect_dots(t_mlx *data, t_vector stt, t_ivector v);
static int	find_info(t_fdf *fdf, char *line);
static int	end(int keycode, void *param);

int	main(int argc, char **argv)
{
	t_mlx		data;
	char		*line;
	int				fd;

	if (argc != 2 || !fp_strnstr(argv[1], ".fdf", fp_strlen(argv[1])))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	line = fp_read_all(fd);
	if (!line)
		return (1);
	if (graphics_init("fdf", &data))
		return (1);
	close(fd);
	if (find_info(data.fdf, line))
		return (graphics_end(&data));
	mlx_hook(data.window, 17, 1L << 17, mlx_loop_end, data.mlx);
	mlx_key_hook(data.window, end, data.mlx);
	draw_map(&data);
	mlx_loop(data.mlx);
	graphics_end(&data);
	return (0);
}

static int	end(int keycode, void *mlx)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(mlx);
	return (1);
}

static int	find_info(t_fdf *fdf, char *line)
{
	t_vector	v;
	t_vector	w;

	fdf->map = fp_splitsplit(line, '\n', ' ');
	fdf->sizy = fp_chrcnt(line, '\n');
	free(line);
	if (!fdf->map)
		return (1);
	fdf->sizx = fp_grdlen(fdf->map[0]);
	fdf->area = fdf->sizx * fdf->sizy;
	v = mtx_iso(mtx_newv(fdf->sizy, 0, fp_atoi(fdf->map[fdf->sizy][0]), 0));
	w = mtx_iso(mtx_newv(0, fdf->sizx, fp_atoi(fdf->map[fdf->sizy][0]), 0));
	fdf->dltx = w.x - v.x;
	v = mtx_iso(mtx_newv(0, 0, fp_atoi(fdf->map[fdf->sizy][0]), 0));
	w = mtx_iso(mtx_newv(fdf->sizy, fdf->sizx,
			fp_atoi(fdf->map[fdf->sizy][0]), 0));
	fdf->dlty = v.y - w.y;
	fdf->cntr = v.x - w.y;
	fdf->sclx = WIDTH / (fdf->dltx + 2);
	fdf->scly = HEIGHT / (fdf->dlty + 2);
	fdf->offx = (WIDTH * .5) - (fdf->dltx * .5);
	fdf->offy = HEIGHT - (fdf->dlty * .3);
	return (0);
}

static void	draw_map(t_mlx *data)
{
	char		***map;
	t_vector	v;
	t_ivector	iv;
	int		i;

	i = -1;
	map = data->fdf->map;
	while (++i < data->fdf->area)
	{
		iv.y = i / data->fdf->sizx;
		iv.x = i % data->fdf->sizx;
		v = mtx_newv(iv.y, iv.x, fp_atoi(map[iv.y][iv.x]),
				fp_atox(fp_strnxt(map[iv.y][iv.x], ',')));
		if (v.x != data->fdf->sizx - 1)
		{
			iv.z = 1;
			connect_dots(data, v, iv);
		}
		if (v.y != data->fdf->sizy - 1)
		{
			iv.z = -1;
			connect_dots(data, v, iv);
		}
	}
	draw_update(data);
}

static void	connect_dots(t_mlx *data, t_vector stt, t_ivector iv)
{
	char		***map;
	t_vector	end;
	int			scl;

	map = data->fdf->map;
	if (iv.z == 1)
		iv.x++;
	if (iv.z == -1)
		iv.y++;
	end = mtx_newv(iv.y, iv.x, fp_atoi(map[iv.y][iv.x]),
			fp_atox(fp_strnxt(map[iv.y][iv.x], ',')));
	if (data->fdf->sclx < data->fdf->scly)
		scl = data->fdf->sclx;
	else
		scl = data->fdf->scly;
	end.x *= scl;
	stt.x *= scl;
	end.y *= scl;
	stt.y *= scl;
	end.z *= (scl * .25);
	stt.z *= (scl * .25);
	stt = mtx_iso(stt);
	end = mtx_iso(end);
	end.x += data->fdf->offx;
	stt.x += data->fdf->offx;
	end.y += data->fdf->offy;
	stt.y += data->fdf->offy;
	draw_line(data, stt, end);
}
