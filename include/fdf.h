/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:44:00 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/08 20:16:30 by fpolaris         ###   ########.fr       */
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
	double		matrix[3][3];
}	t_fdfdata;

t_fdfdata	*fdf_read_map(char *name);
int		fdf_draw_map(t_wireframe **grid, t_fdfdata *data,
			t_vector (*fp) (const t_vector),
			t_vector (*mtx) (const t_vector, double matrix[3][3]);

#endif
