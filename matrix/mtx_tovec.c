#include "libgraph.h"

t_vector	mtx_tovec(t_matrix m)
{
	t_vector	v;


	if (m.col == 1 && m.row == 3)
	{
		v.x = m.elem[0][0];
		v.y = m.elem[0][1];
		v.z = m.elem[0][2];
	}
	else if (m.col == 3 && m.row == 1)
	{
		v.x = m.elem[0][0];
		v.y = m.elem[1][0];
		v.z = m.elem[2][0];
	}
	return (v);
}
