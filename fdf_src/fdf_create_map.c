/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:20:43 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/11 20:58:21 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

static t_vector	**st_fill(t_vector **map, char **src, int col, int row);
static int	st_find_scale(int col, int row);
static t_vector	**st_allocate(int col, int row);
static t_vector	st_sizes(char *src);

t_vector	**fdf_create_map(t_vector **map, char *src)
{
	t_vector	size;

	size = st_sizes(src);
	if (size.z == -1)
		return (NULL);
	map = st_allocate(size.x, size.y);
	map = st_fill(map, fp_split(src, ' '), size.x, size.y);
	return (map);
}

static t_vector	st_sizes(char *src)
{
	t_vector	v;
	char	**collums;
	char	**rows;

	rows = fp_split(src, '\n');
	v.y = 0;
	v.z = -1;
	collums = fp_split(rows[(int)v.y], ' ');
	v.x = fp_grdlen(collums);
	while (++v.y < fp_grdlen(rows))
	{
		if (fp_grdlen(collums) > v.x)
			return (v);
		fp_grdfre(collums);
		collums = fp_split(rows[(int)v.y], ' ');
	}
	fp_grdfre(rows);
	if (collums)
		fp_grdfre(collums);
	v.z = 0;
	return (v);
}

static t_vector	**st_allocate(int col, int row)
{
	int			i;
	t_vector	**map;

	i = -1;
	map = (t_vector **)fp_calloc(row, sizeof(t_vector *));
	while (++i < row)
		map[i] = (t_vector *)fp_calloc(col, sizeof(t_vector));
	return (map);
}

static t_vector	**st_fill(t_vector **map, char **src, int col, int row)
{
	int	i;
	int	x;
	int	y;
	int	size;
	int	scale;

	i = -1;
	scale = st_find_scale(col, row);
	size = fp_grdlen(src);
	while (++i < col * row)
	{
		x = i % col;
		y = i / col;
		map[x][y].x = x * scale;
		map[x][y].y = y * scale;
		map[x][y].z = fp_atoi(src[i]) * scale;
		map[x][y].color = 0;
		if (fp_strchr(src[i], ','))
			map[x][y].color = fp_atox(fp_strchr(src[i], ','));
	}
	fp_grdfre(src);
	return(map);
}

static int	st_find_scale(int col, int row)
{
	if (WIDTH > HEIGHT)
		return (HEIGHT / row);
	return (WIDTH / col);
}
