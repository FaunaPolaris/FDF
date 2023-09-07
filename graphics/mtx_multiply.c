/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:14:02 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/07 19:53:04 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

double	(*mtx_multiply3d(double matrix1[3][3], double matrix2[3][3]))[3][3]
{
	double	output[3][3];
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			output[i][j] = 0.0;
			k = -1;
			while (++k < 3)
			{
				output[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return (output);
}
