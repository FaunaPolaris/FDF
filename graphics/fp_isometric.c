/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:46:26 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/19 09:34:24 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	fp_isometric(t_vector *vertx, int quantity)
{
	int	i;
	double	new_x;
	double	new_y;

	i = 0;
	while (i < quantity)
	{
		new_x = (vertx[i].x - vertx[i].y) * cos(0.5236);
		new_y = -vertx[i].z + (vertx[i].x + vertx[i].y) * sin(0.5236);
		vertx[i].x = new_x;
		vertx[i].y = new_y;
		i++;
	}
}
