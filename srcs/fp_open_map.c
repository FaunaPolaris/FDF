/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:42:36 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/24 13:08:36 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fp_new_node(t_map *head, int x, int y, int z)
{
	t_map	*new;
	t_map	*temp;

	temp = head;
	new = (t_map *)fp_calloc(1, sizeof(t_map));
	if (!new)
		return (1);
	new->vertice.x = x * SCALE;
	new->vertice.y = y * SCALE;
	new->vertice.z = z * SCALE / 4;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (0);
}

static char	**fp_get_array(int fd)
{
	char	*line;
	char	**array;

	line = get_next_line(fd);
	array = fp_split(line, ' ');
	free(line);
	return (array);
}

static	int	fp_main_loop(int *y, int fd, t_map *map)
{
	int	x;
	char	**array;
	int	high_x;

	high_x = 0;
	while (1)
	{
		array = fp_get_array(fd);
		if (!array)
			break ;
		x = 0;
		while (array[x])
		{
			if (fp_new_node(map, x, y[0], fp_atoi(array[x])))
				break ;
			free(array[x]);
			x++;
		}
		if (x > high_x)
			high_x = x;
		free(array);
		y[0]++;
	}
	return (high_x);
}

t_map	*fp_open_map(int fd)
{
	t_map	*map;
	t_map	*temp;
	int		y;
	int		x;

	y = 0;
	map = (t_map *)fp_calloc(1, sizeof(t_map));
	x = fp_main_loop(&y, fd, map);
	temp = map->next;
	fp_new_node(map, -1, -1, 0);
	while (temp->next->vertice.y >= 0)
	{
		temp->isometric = temp->vertice;
		fp_printf("x: %i, y: %i %20s", (int)temp->vertice.x, (int)temp->vertice.y, "|");
		fp_isometric(&temp->isometric, 1);
		temp = temp->next;
	}
	map->vertice.x = x;
	map->vertice.y = y;
	return (map);
}
