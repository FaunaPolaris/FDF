/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_applymatrix3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:56:46 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/07 13:11:31 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	fp_applymatrix3d(t_vector *vector, double (*matrix)[3][3])
{
	double	x;
	double	y;
	double	z;

	x = vector->x;
	y = vector->y;
	z = vector->z;
	vector->x = (x * (*matrix)[0][0]) + (y * (*matrix)[0][1]) +
				(z * (*matrix)[0][2]);
	vector->y = (x * (*matrix)[1][0]) + (y * (*matrix)[1][1]) +
				(z * (*matrix)[1][2]);
	vector->z = (x * (*matrix)[2][0]) + (y * (*matrix)[2][1]) +
				(z * (*matrix)[2][2]);
}
