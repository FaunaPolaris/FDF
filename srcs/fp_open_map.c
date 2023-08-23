/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:42:36 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/23 17:35:58 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fp_new_node(t_map *head, char *line, int y, int x)
{
	t_map	*new;
	t_map	*temp;

	temp = head;
	new = (t_map *)fp_calloc(1, sizeof(t_map));
	if (!new)
		return (1);
	new->vertice.x = x * SCALE;
	new->vertice.y = y * SCALE;
	new->vertice.z = fp_atoi(line) * SCALE;
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

t_map	*fp_open_map(int fd)
{
	t_map	*map;
	int		y;
	int		x;
	char	**array;

	y = 0;
	map = (t_map *)fp_calloc(1, sizeof(t_map));
	while (1)
	{
		array = fp_get_array(fd);
		if (!array)
			break ;
		x = 0;
		while (array[x])
		{
			if (fp_new_node(map, array[x], y, x))
				break ;
			free(array[x]);
			x++;
		}
		free(array);
		y++;
	}
	return (map);
}
