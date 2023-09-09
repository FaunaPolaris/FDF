#include "libgraph.h"

t_matrix	mtx_null(void)
{
	t_matrix	mtx;

	mtx = (t_matrix){0, 0, 0, NULL};
	return (mtx);
}
