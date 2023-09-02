/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:06:13 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/01 20:10:03 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	fp_putline(t_mlx *data, t_vector point_a, t_vector point_b, int color)
{
	double	t;
	int	x;
	int	y;

	t = 0;
	while (t <= 1)
	{
		x = ((1 - t) * point_a.x + (t * point_b.x)) + WIDTH / 2;
		y = ((1 - t) * point_a.y + (t * point_b.y)) + HEIGHT / HGHT_SCL;
		fp_putpixel(data, x, y, color);
		t += 0.008;
	}
}
