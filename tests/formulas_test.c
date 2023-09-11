#include "libgraph.h"
#include "formulas.h"

int	main(int argc, char **argv)
{
	t_mlx	data;

	if (argc != 2)
		return (1);
	if (graphics_init("Formula Projection", &data))
		return (1);
	if (argv[1][0] == 'B')
		draw_butterfly(&data, mtx_centerv());
	graphics_end(&data);
}
