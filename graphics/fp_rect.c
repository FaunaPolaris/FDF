#include "libgraph.h"

t_vector	*fp_rect(int width, int height, int depth)
{
	t_vector	*vertice;
	int	i;

	if (!(vertice = (t_vector *)malloc(sizeof(t_vector) * 8)))
		return (vertice);
	i = 0;
	while (i < 4)
	{
		vertice[i].x = 0;
		vertice[i].y = 0;
		vertice[i].z = 1;
		i++;
	}
	vertice[1].y += height;
	vertice[2].y += height;
	vertice[2].x += width;
	vertice[3].x += width;
	while (i < 8)
	{
		vertice[i] = vertice[i - 4];
		i++;
	}
	i = 4;
	while (i < 8)
	{
		vertice[i].z += depth;
		i++;
	}
	return (vertice);
}
// 	0	3	4	7

// 	1	2	5	6
