/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_rotxvertice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:07:23 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/15 16:20:42 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	fp_rotxvertice(t_vector *vertice, int quantity, double angle)
{
	int	i;

	i = 0;
	while (i < quantity)
	{
		vertice[i].y = (vertice[i].y * cos(angle))
				- (vertice[i].z * sin(angle));
		vertice[i].z = (vertice[i].y * sin(angle))
				+ (vertice[i].z * cos(angle));
		i++;
	}
}
