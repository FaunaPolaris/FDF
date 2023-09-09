#include "libgraph.h"

int	main(int argc, char **argv)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	c;

	if (argc != 3)
		return (1);
	a = mtx_new(3, 3);
	b = mtx_new(3, 3);
	mtx_fill(&a, argv[1]);
	mtx_fill(&b, argv[2]);
	c = mtx_multiply(a, b);
	mtx_print(a);
	mtx_print(b);
	fp_printf("=\n");
	mtx_print(c);
	mtx_free(a);
	mtx_free(b);
	mtx_free(c);
	return (0);
}
