/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_isometry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:46:26 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/13 18:07:12 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vector	mtx_iso(const t_vector vertx)
{
	t_vector	output;
	double		temp;

	temp = M_PI / 180;
	output.x = (vertx.x - vertx.y) * cos(45 * temp);
	output.y = (-vertx.z + vertx.x + vertx.y)
			* sin(-30 * temp);
	output.z = vertx.z;
	output.color = vertx.color;
	return (output);
}
