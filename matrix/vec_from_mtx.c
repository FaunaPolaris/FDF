#include "libgraph.h"

t_vector	vec_from_mtx(t_matrix m)
{
	t_vector	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
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
