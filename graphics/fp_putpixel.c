/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:49:51 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/08 19:35:46 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

void	fp_pixelput(t_mlx *data, int x, int y, int color)
{
	char	*position;

	position = data->img->addr + (y * data->img->line
			+ (x * data->img->bits / 8));
	*(unsigned int *)position  = color;
}
