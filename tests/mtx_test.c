#include "libgraph.h"

int	main(int argc, char **argv)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	aux;
	t_vector	v;

	a = mtx_new(3, 3);
	aux = mtx_new(1, 3);
	if (mtx_fill(&a, argv[1]) || mtx_fill(&aux, argv[2]) || argc != 3)
	{
		fp_printf("Invalid input\n");
		mtx_free(a);
		mtx_free(aux);
		return (1);
	}
	v = mtx_tovec(aux);
	mtx_free(aux);
	b = mtx_fromv(v, 1);
	mtx_print(a);
	mtx_print(b);
	aux = mtx_multiply(a, b);
	mtx_print(aux);
	mtx_free(a);
	mtx_free(b);
	mtx_free(aux);
	return (0);
}
