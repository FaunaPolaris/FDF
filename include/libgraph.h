/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:42:48 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/27 12:44:05 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
#define LIBGRAPH_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "colors.h"

# define WIDTH 1280
# define HEIGHT 720
# define SCALE 10

typedef struct s_wireframe
{
	t_vector	vertice;
	s_octree	*xplus;
	s_octree	*xmins;
	s_octree	*yplus;
	s_octree	*ymins;
}	t_wireframe

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
}	t_img_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	t_img_data	*img;
}	t_mlx;

int	fp_graphical_init(char *title, t_mlx *data);
void	fp_graphical_end(t_mlx *data);

void	fp_putpixel(t_mlx *data, int x, int y, int color);
void	fp_putvertice(t_mlx *data, t_vector *vertx, int quantity, int color);
void	fp_putline(t_mlx *data, t_vector point_a, t_vector point_b);
void	fp_putrect(t_mlx *data, t_vector *vertice);

t_vector	*fp_rect(int width, int height, int depth);

void	fp_set_all(t_mlx *data, int color);

void	fp_rotxvertice(t_vector *vertx, int quantity, double angle);

void	fp_isometric(t_vector *vertx, int quantity);
t_vector	fp_find_center(void);

#endif
