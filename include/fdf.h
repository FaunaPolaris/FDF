/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:44:00 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/11 20:39:44 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libgraph.h"

t_vector	**fdf_create_map(t_vector **map, char *src);
void		fdf_draw_map(t_mlx *data, t_vector **map,
			t_vector (*mtx) (const t_vector));


#endif
