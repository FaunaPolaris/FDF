/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_close_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:02:59 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/23 16:24:38 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fp_close_map(t_map *map)
{
	t_map	*temp;
	t_map	*temp2;

	temp = map->next;
	while (temp)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	free(map);
}
