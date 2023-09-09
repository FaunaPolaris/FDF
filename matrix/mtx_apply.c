/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_applymatrix3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:56:46 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/08 19:19:15 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vector	mtx_apply(const t_vector vector, const t_matrix m)
{
	t_vector	output;

	x = vector.x;
	y = vector.y;
	z = vector.z;
	output.x = (x * (*matrix)[0][0]) + (y * (*matrix)[0][1]) +
				(z * (*matrix)[0][2]);
	output.y = (x * (*matrix)[1][0]) + (y * (*matrix)[1][1]) +
				(z * (*matrix)[1][2]);
	output.z = (x * (*matrix)[2][0]) + (y * (*matrix)[2][1]) +
				(z * (*matrix)[2][2]);
	return (output);
}
