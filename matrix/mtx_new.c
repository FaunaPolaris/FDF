#include "libgraph.h"

t_matrix	mtx_new(int col, int row)
{
	t_matrix	output;
	int		i;

	if (col == 0 || row == 0)
		return (mtx_null());
	output.size = col * row;
	i = -1;
	output.elem = (double **)fp_calloc(col, sizeof(double *));
	while (++i < col)
		output.elem[i] = (double *)fp_calloc(row, sizeof(double));
	output.col = col;
	output.row = row;
	return (output);
}

void	mtx_free(t_matrix m)
{
	int	i;

	i = -1;
	while (++i < m.col)
		free(m.elem[i]);
	free(m.elem);
}
