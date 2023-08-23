/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:49:51 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/23 17:39:04 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	fp_putpixel(t_mlx *data, int x, int y, int color)
{
	char	*position;

	if (x > WIDTH || y > HEIGHT)
		return ;
	if (x < 0 || y < 0)
		return ;
	position = data->img->addr + (y * data->img->line
			+ (x * data->img->bits / 8));
	*(unsigned int *)position  = color;
}
