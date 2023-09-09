#include "libgraph.h"

void	mtx_fill(t_matrix *m, char *content)
{
	int		i;
	char	**split;

	split = fp_split(content, ' ');
	i = -1;
	while (++i < m->size)
	{
		m->elem[i / m->col][i % m->col] = fp_atoi(split[i]);
	}
	i = -1;
	while (split[++i])
	{
		free(split[i]);
	}
	free(split);
}
