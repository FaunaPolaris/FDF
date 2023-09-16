/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:42:48 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/13 11:49:25 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
#define LIBGRAPH_H

# include <mlx.h>
# include "libft.h"
# include "colors.h"
# include "keys.h"
# include "matrix.h"

# define WIDTH 1280
# define HEIGHT 720

# define PRECISION 0.001

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
	t_constants	*mtx;
	t_img_data	*img;
}	t_mlx;

int	graphics_init(char *title, t_mlx *data);
void	graphics_end(t_mlx *data);

void	draw_pixel(t_img_data *img, int x, int y, int color);
void	draw_point(t_mlx *data, t_vector vertx, int color);
void	draw_line(t_mlx *data, t_vector point_a, t_vector point_b);
void	draw_square(t_mlx *data, t_vector topl, t_vector botr, int fill);
void	draw_cube(t_mlx *data, t_vector start, t_vector end,
		t_vector (*pers) (t_constants *, const t_vector));
void	draw_plane(t_mlx *data, t_vector start, t_vector end,
		t_vector (*pers) (t_constants *, const t_vector));
void	draw_circle(t_mlx *data, t_vector center, int radius, int color);
void	draw_butterfly(t_mlx *data, t_vector center);
void	draw_fill(t_mlx *data, t_vector start, t_vector end, int color);
void	draw_update(t_mlx *data);

void	drac_pixel(t_img_data *img, int x, int y, int color);

#endif
