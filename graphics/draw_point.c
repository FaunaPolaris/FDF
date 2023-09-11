#include "libgraph.h"

void	draw_point(t_mlx *data, t_vector vertice, int color)
{
	draw_pixel(data,vertice.x, vertice.y, color);
	draw_update(data);
}
