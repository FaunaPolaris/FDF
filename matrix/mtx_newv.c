/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_newv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:18:37 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/13 12:11:24 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vector	mtx_newv(double y, double x, double z, int color)
{
	static t_vector	output;

	output.y = y;
	output.x = x;
	output.z = z;
	output.color = color;
	return (output);
}
