#include "matrix.h"

t_constants	*mtx_init(void)
{
	t_constants	*output;

	output = (t_constants *)fp_calloc(1, sizeof(t_constants));
	output->convert_to_radian = M_PI / 180;
	output->cos_p45 = cos(45 * output->convert_to_radian);
	output->sin_n30 = sin(-30 * output->convert_to_radian);
	return (output);
}
