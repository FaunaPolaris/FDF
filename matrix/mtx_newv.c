/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_newv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:18:37 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/12 11:20:00 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vector	mtx_newv(double x, double y, double z, int color)
{
	t_vector	output;

	output.x = x;
	output.y = y;
	output.z = z;
	output.color = color;
	return (output);
}
