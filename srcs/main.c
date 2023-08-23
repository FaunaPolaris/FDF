/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:53:56 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/23 17:21:20 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	t_mlx	data;
	t_map	*map;

	map = NULL;
	if (argc != 2)
		return (1);
	if (fp_graphical_init("fdf", &data))
		return (1);
	fd = open(argv[1], O_RDONLY);
	map = fp_open_map(fd);
	fp_draw_map(&data, map);
	usleep(10000 * 500);
	fp_close_map(map);
	fp_graphical_end(&data);
	close(fd);
}
