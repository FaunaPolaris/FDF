/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_identity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:51:15 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/08 20:01:59 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	mtx_identity3(double matrix[3][3])
{
	double	output[3][3];
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (i == j)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
		}
	}
}
