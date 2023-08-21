/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_set_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:14:26 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/21 10:17:52 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	fp_set_all(t_mlx *data, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fp_putpixel(data, x, y, color);
			y++;
		}
		x++;
	}
}
