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
	int			x;
	int			y;

	i = -1;
	if (a.row != b.col)
		return (mtx_null());
	c = mtx_new(a.row, b.col);
	while (++i < c.size)
	{
		j = -1;
		while (++j < c.row)
		{
			x = i / c.col;
			y = i % c.col;
			c.elem[x][y] += a.elem[x][j] * b.elem[j][y];
			if (j == 0)
				fp_printf("C(%i, %i) = ", i / c.col, i % c.col);
			fp_printf("A(%i, %i) * B(%i, %i)", x, j, j, y);
			if (j != c.col - 1)
				fp_printf(" + ");
		}
		fp_printf("\n");
	}
	return (c);
}
