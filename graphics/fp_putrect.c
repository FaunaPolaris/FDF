#include "libgraph.h"

void	fp_putrect(t_mlx *data, t_vector *vertice)
{
	for (int i = 0; i < 3; i++)
		fp_putline(data, vertice[i], vertice[i + 1], 0xFF0000);
	fp_putline(data, vertice[3], vertice[0], 0xFF0000);
	for (int i = 4; i < 7; i++)
		fp_putline(data, vertice[i], vertice[i + 1], 0xFF0000);
	fp_putline(data, vertice[7], vertice[4], 0xFF0000);
	for (int i = 0; i < 4; i++)
		fp_putline(data, vertice[i], vertice[i + 4], 0xFF0000);
}
