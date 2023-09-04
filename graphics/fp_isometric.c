/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:46:26 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/04 14:56:37 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vector	fp_isometric(const t_vector vertx)
{
	t_vector	output;

	output.x = (vertx.x - vertx.y) * cos(0.5236);
	output.y = (-vertx.z / HGHT_SCL) + (vertx.x + vertx.y) * sin(0.5236);
	return (output);
}
