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

t_matrix	mtx_identity(int size)
{
	t_matrix	output;
	int			i;
	int			j;

	output = mtx_new(size, size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (i == j)
				output.elem[i][j] = 1;
			else
				output.elem[i][j] = 0;
		}
	}
	return (output);
}
