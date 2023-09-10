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
		return (mtx_null());
	c = mtx_new(b.col, a.row);
	while (++i < b.col)
	{
		j = -1;
		while (++j < b.row)
		{
			k = -1;
			while (++k < b.col)
			{
				c.elem[i][j] += a.elem[i][k] * b.elem[k][j];
			}
		}
	}
	return (c);
}
