#include "libgraph.h"

int	main(void)
{
	t_mlx	mlx;

	// start conways game of life:
	if (graphics_init("genetics", &mlx))
		return (1);
}
