#include "libgraph.h"

t_matrix	mtx_fromv(t_vector source, int col)
{
	t_matrix	output;

	if (col == 1)
	{
		output = mtx_new(1, 3);
		output.elem[0][0] = source.x;
		output.elem[0][1] = source.y;
		output.elem[0][2] = source.z;
	}
	else if (col == 3)
	{
		output = mtx_new(3, 1);
		output.elem[0][0] = source.x;
		output.elem[1][0] = source.y;
		output.elem[2][0] = source.z;
	}
	else
		return (mtx_null());
	return (output);
}
