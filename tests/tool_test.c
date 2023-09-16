#include "libgraph.h"

int	main(void)
{
	t_mlx	data;
	t_vector	center;
	t_vector	aux;

	if (graphics_init("tool", &data))
		return (1);
	center = vec_center();
	center.color = 0x00AA22;
	aux = center;
	fp_printf("starting tests...\n");
	draw_point(&data, center, 0xFF);
	aux.x -= 100;
	aux.y -= 100;
	aux.z -= 100;
	aux.color = 0x00AA22;
	draw_cube(&data, center, aux, vec_isometry);
	usleep(1000 * 5000);
	graphics_end(&data);
}
