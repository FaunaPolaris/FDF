#include "matrix.h"

t_constants	*mtx_init(void)
{
	t_constants	*output;
	double		radian;

	output = (t_constants *)fp_calloc(1, sizeof(t_constants));
	radian = M_PI / 180;
	output->cos_p45 = cos(45 * radian);
	output->sin_n30 = sin(-30 * radian);
	return (output);
}
