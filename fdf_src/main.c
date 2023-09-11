/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:35:20 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/11 20:38:50 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_mlx	data;
	char	*temp;
	t_vector	**map;
	int		fd;

	map = NULL;
	if (argc != 2 || !fp_strnstr(argv[1], ".fdf", fp_strlen(argv[1])))
		return (1);
	if (graphics_init("fdf", &data))
		return (1);
	fd = open(argv[1], O_RDONLY);
	temp = fp_read_all(fd);
	map = fdf_create_map(map, temp);
	if (!map)
		return (1);
	fdf_draw_map(&data, map, mtx_isometry);
	draw_update(&data);
	usleep(1000 * 500);
	close(fd);
	graphics_end(&data);
}
