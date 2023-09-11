/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:49:51 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/11 17:49:37 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	draw_pixel(t_mlx *data, int x, int y, int color)
{
	char	*position;

	if (x > WIDTH - 1 || y > HEIGHT - 1)
		return ;
	if (x < 0 || y < 0)
		return ;
	y = -y + HEIGHT;
	position = data->img->addr + (y * data->img->line
			+ (x * data->img->bits / 8));
	*(unsigned int *)position  = color;
}
