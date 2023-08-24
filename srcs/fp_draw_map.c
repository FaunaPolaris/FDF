/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:54:20 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/24 13:15:12 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_liney(t_mlx *data, t_map *map, int line)
{
	t_map	*temp;

	temp = map->next;
	while (temp->vertice.y != line * SCALE && temp->next->vertice.y >= 0)
		temp = temp->next;
	while (temp->next->vertice.y == line * SCALE
			&& temp->next->next->vertice.y >= 0)
	{
		fp_putline(data, temp->isometric, temp->next->isometric);
		temp = temp->next;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img->img,
				0, 0);
}

static void	draw_linex(t_mlx *data, t_map *map, int collum)
{
	t_map	*last;
	t_map	*current;
	int		i;

	i = 0;
	last = map->next;
	current = map->next;
	while (i < map->vertice.x * map->vertice.y * SCALE
			&& current->next->next->vertice.y >= 0)
	{
		current = current->next;
		if (current->vertice.x == collum * SCALE)
		{
			fp_putline(data, current->isometric, last->isometric);
			last = current;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img->img,
				0, 0);
}

void	fp_draw_map(t_mlx *data, t_map *map)
{
	int	i;

	i = 0;
	while (i++ < map->vertice.x)
		draw_liney(data, map, i - 1);
	i = 0;
	while (i++ < map->vertice.y)
		draw_linex(data, map, i - 1);
}
