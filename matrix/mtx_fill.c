#include "libgraph.h"

static int	st_free(char **split);

int	mtx_fill(t_matrix *m, char *content)
{
	int		i;
	int		x;
	int		y;
	char	**split;

	split = fp_split(content, ' ');
	if (fp_gridlen(split) != m->size)
		return (st_free(split));
	i = -1;
	while (++i < m->size)
	{
		x = i / m->col;
		y = i % m->col;
		if (m->col == m->row)
			m->elem[x][y] = fp_atoi(split[i]);
		else
			m->elem[y][x] = fp_atoi(split[i]);
	}
	st_free(split);
	return (0);
}

static int	st_free(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		free(split[i]);
	}
	free(split);
	return (1);
}
