/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:06:13 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/13 10:40:40 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	draw_line(t_mlx *data, t_vector point_a, t_vector point_b)
{
	double	t;
	int	x;
	int	y;
	int	hypo;
	int	i;

	i = -1;
	hypo = (int)(sqrt(pow(point_a.x - point_b.x, 2)) +
		pow(point_a.y - point_b.y, 2));
	while (++i < hypo)
	{
		t = (double)i / hypo;
		x = fp_ilerp(point_a.x, point_b.x, t);
		y = fp_ilerp(point_a.y, point_b.y, t);
		t = fp_lerpcolor(point_a.color, point_b.color, t);
		draw_pixel(data, x, y, t);
	}
}
