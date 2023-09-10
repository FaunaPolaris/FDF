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

t_matrix	mtx_multiply(const t_matrix a, const t_matrix b)
{
	t_matrix	c;
	int			i;
	int			j;
	int			k;

	i = -1;
	if (a.col != b.row)
	{
		fp_printf("Invalid Operation\n");
		return (mtx_null());
	}
	c = mtx_new(b.col, a.row);
	while (++i < a.row)
	{
		j = -1;
		while (++j < b.col)
		{
			k = -1;
			while (++k < a.row)
			{
				c.elem[j][i] += a.elem[i][k] * b.elem[j][k];
			}
		}
	}
	return (c);
}
