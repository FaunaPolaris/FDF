#include "libgraph.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_mlx	data;
	t_vector	*vertice;

	if (argc != 4)
		return (1);
	if (fp_graphical_init("cube", &data))
		return (1);
	vertice = fp_rect(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	fp_isometric(vertice, 8);
	fp_putvertice(&data, vertice, 8, 0xFF00FF);
	usleep(500 * 10000);
	free(vertice);
	fp_graphical_end(&data);
	return (0);
}
