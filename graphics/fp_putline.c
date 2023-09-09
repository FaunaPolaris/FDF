/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:06:13 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/07 18:47:13 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	fp_putline(t_mlx *data, t_vector point_a, t_vector point_b)
{
	double	t;
	double	x;
	double	y;
	int	c_temp;

	t = 0;
	while (t <= 1)
	{
		x = fp_lerp(point_a.x, point_b.x, t) + WIDTH / 2;
		y = -fp_lerp(point_a.y, point_b.y, t) + HEIGHT / 2;
		c_temp = fp_lerpcolor(point_a.color, point_b.color, t);
		fp_putpixel(data, (int)x, (int)y, c_temp);
		t += PRECISION;
	}
}
