#include "libgraph.h"

int	main(int argc, char **argv)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	c;
	t_vector	v;

	v.x = argv[1][0] - 48;
	v.y = argv[1][2] - 48;
	v.z = argv[1][4] - 48;

	if (argc != 3)
		return (1);
	a = mtx_fromv(v, 1);
	b = mtx_new(3, 3);
	mtx_fill(&b, argv[2]);
	mtx_print(a);
	mtx_print(b);
	c = mtx_multiply(b, a);
	fp_printf("=\n");
	mtx_print(c);
	mtx_free(a);
	mtx_free(b);
	mtx_free(c);
	return (0);
}
