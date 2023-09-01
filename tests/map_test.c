#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fdfdata	map;
	int	fd;

	fp_printf("initializing test\n");
	printf("Opening Map: %s\n", argv[1]);
	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	map = fdf_check_map(fd, argv[1]);
	if (map.max_x < 1 || map.max_y < 1)
		return (1);
	fp_printf("(%i, %i, %i)\n", map.max_x, map.max_y, map.max_z);
	close(fd);
	return (0);
}
