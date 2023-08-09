#include "libgraph.h"

int	main(int argc, char **argv)
{
	t_mlx	data;

	if (argc != 2)
		return (1);
	if (fp_graphical_init("Formula Projection", &data))
		return (1);
	if (argv[1][0] == 'B')
		fp_butterfly(&data, fp_find_center());
	fp_graphical_end(&data);
}
