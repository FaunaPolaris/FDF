#include "libgraph.h"

void	mtx_print(t_matrix m)
{
	int	i;
	int	x;
	int	y;

	fp_printf("collums: %i | rows: %i\n",
			m.col, m.row);
	i = -1;
	while (++i < m.size)
	{
	 	x = i / m.col;
		y = i % m.col;
		fp_printf("%5i", (int)m.elem[x][y]);
		if (y == m.col - 1)
			fp_printf("\n");
	}
	fp_printf("\n");
	}
