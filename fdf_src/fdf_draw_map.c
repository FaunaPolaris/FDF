/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:57:54 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/08 20:15:34 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_draw_map(t_wireframe **grid, t_fdfdata *data,
		t_vector (*fp) (const t_vector),
		t_vector (*mtx) (const t_vector, double matrix[3][3]))
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->max_x)
	{
		j = -1;
		while (++j < data->max_y)
		{
			if (i != data->max_x)
				fp_putline(data->mlx, fp(mtx(grid[i][j].vertice,
					data->matrix)),
					fp(mtx(grid[i][j].xplus->vertice,
					data->matrix)), grid[i][j].color);
			if (j != data->max_y)
				fp_putline(data->mlx, fp(mtx(grid[i][j].vertice,
					data->matrix)),
					fp(mtx(grid[i][j].yplus->vertice,
					data->matrix)), grid[i][j].color);
		}
	}
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->window,
		data->mlx->img->img, 0, 0);
	return (1);
}
