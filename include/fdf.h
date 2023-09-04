/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:44:00 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/04 13:59:30 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libgraph.h"

typedef struct s_fdfdata
{
	t_mlx		*mlx;
	t_wireframe	**grid;
	int		max_x;
	int		max_y;
	int		max_z;
}	t_fdfdata;

t_fdfdata	*fdf_read_map(char *name);
int		fdf_draw_map(t_wireframe **grid, t_fdfdata *data,
				t_vector (*fp) (const t_vector));

#endif
