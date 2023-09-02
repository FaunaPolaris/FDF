/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:57:54 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/01 20:13:21 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_draw_map(t_wireframe **grid, t_fdfdata *data,
				t_vector (*fp) (const t_vector))
{
	int	i;
	int	j;

	i = 0;
	while (i < data->max_x)
	{
		j = 0;
		while (j < data->max_y)
		{
			if (i != data->max_x - 1)
				fp_putline(data->mlx, fp(grid[i][j].vertice),
						fp(grid[i][j].xplus->vertice),
						grid[i][j].color);
			if (j != data->max_y - 1)
				fp_putline(data->mlx, fp(grid[i][j].vertice),
						fp(grid[i][j].yplus->vertice),
						grid[i][j].color);
			j++;
//			usleep(10 * 500);
		}
		i++;
		mlx_put_image_to_window(data->mlx->mlx,
					data->mlx->window,
					data->mlx->img->img, 0, 0);
	
	}
	return (1);
}
