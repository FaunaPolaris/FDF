#include "libgraph.h"

void	draw_fill(t_mlx *data, t_vector start, t_vector end, int gradient)
{
	t_vector	aux;

	aux = end;
	if (!gradient)
		aux.color = start.color;
	while (start.x < end.x)
	{
		aux.x = start.x;
		draw_line(data, start, aux);
		start.x++;
	}
	draw_update(data);
}
