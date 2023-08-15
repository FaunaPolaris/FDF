#include "libgraph.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_mlx	data;
	t_vector	*vertice;
	int	i = 0;

	if (argc != 4)
		return (1);
	if (fp_graphical_init("cube", &data))
		return (1);
	vertice = fp_rect(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	while (i < 100)
	{
		fp_putvertice(&data, vertice, 8, 0xFF00FF);
		usleep(1000 * 500);
//		fp_rotxvertice(vertice, 8, 0.5);
		i++;
	}
	free(vertice);
	fp_graphical_end(&data);
	return (0);
}
