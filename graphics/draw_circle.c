/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 02:25:36 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/15 04:38:52 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	draw_circle(t_mlx *data, t_vector center, int radius, int color)
{
	int	x;
	int	y;
	double	angle;
	double	radian;

	angle = 0;
	while (angle < 320)
	{
		radian = angle / (M_PI / 180);
		x = radius * cos(radian);
		y = radius * sin(radian);
		draw_pixel(data, x + center.x, y + center.y, color);
		angle += PRECISION;
	}
	draw_update(data);
}
