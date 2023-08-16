/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:46:26 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/16 13:51:57 by fpolaris         ###   ########.fr       */
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
		new_x = (vertx[i].x * 0.707) + (vertx[i].y * 0.707);
		new_y = (vertx[i].x * -0.707) + (vertx[i].y * 0.707);
		vertx[i].x = new_x;
		vertx[i].y = new_y;
		i++;
	}
}
