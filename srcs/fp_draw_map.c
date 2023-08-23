/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:54:20 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/23 17:08:55 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fp_draw_map(t_mlx *data, t_map *map)
{
	t_map	*current;

	current = map->next;
	while (current)
	{
		fp_isometric(&current->vertice, 1);
		fp_putvertice(data, &current->vertice, 1, 0xFF00FF);
		current = current->next;
	}
}
