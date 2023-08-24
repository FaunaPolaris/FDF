/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:44:00 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/24 10:40:58 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

typedef struct s_map
{
	t_vector	vertice;
	t_vector	isometric;
	struct s_map	*next;
}	t_map;

t_map	*fp_open_map(int fd);
void	fp_close_map(t_map *map);
void	fp_draw_map(t_mlx *data, t_map *map);
