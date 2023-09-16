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

t_vector	vec_isometry(t_constants *mtx, const t_vector vertx)
{
	t_vector	output;

	output.x = (vertx.x - vertx.y) * mtx->cos_p45;
	output.y = (-vertx.z + vertx.x + vertx.y)
			* mtx->sin_n30;
	return (output);
}
