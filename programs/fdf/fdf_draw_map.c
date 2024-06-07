/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:53:18 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/11 17:18:45 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	fdf_draw_map(t_mlx *data, t_vector **map,
		t_vector (*mtx) (const t_vector))
{
	int	i;
	int	col;
	int	x;
	int	y;

	i = -1;
	col = -1;
	while (map[++col])
		;
	while (map[++i])
	{
		x = i / col;
		y = i % col;
		map[x][y] = mtx(map[x][y]);
		if (x != 0)
			draw_line(data, map[x][y], map[x - 1][y]);
		if (y != 0)
			draw_line(data, map[x][y], map[x][y - 1]);
	}
}
