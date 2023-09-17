/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:49:51 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/14 10:20:49 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	draw_pixel(t_mlx *data, int x, int y, int color)
{
	char	*position;

	if (x > WIDTH - 1 || y > HEIGHT - 1 || x < 0 || y < 0)
		return ;
	y = -y + HEIGHT;
	position = data->img->addr + (y * data->img->line
			+ (x * data->img->bits / 8));
	*(unsigned int *)position  = color;
}

void	drac_pixel(t_mlx *data, int x, int y, int color)
{
	char	*position;

	if (x > WIDTH - 1)
		drac_pixel(data, x - WIDTH, y, color);
	if (y > HEIGHT - 1)
		drac_pixel(data, x, y - HEIGHT, color);
	if (x < 0)
		drac_pixel(data, x + WIDTH, y, color);
	if (y < 0)
		drac_pixel(data, x, y + HEIGHT, color);
	if (x > WIDTH - 1 || y > HEIGHT - 1 || x < 0 || y < 0)
		return ;
	y = -y + HEIGHT;
	position = data->img->addr + (y * data->img->line
			+ (x * data->img->bits / 8));
	*(unsigned int *)position  = color;
}
