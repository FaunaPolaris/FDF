/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_isometry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:46:26 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/11 17:27:54 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vector	mtx_isometry(const t_vector vertx)
{
	t_vector	output;
	double		temp;

	temp = M_PI / 180;
	output.x = (vertx.x - vertx.y) * cos(45 * temp);
	output.y = (-vertx.z + vertx.x + vertx.y)
			* sin(30 * temp);
	return (output);
}
