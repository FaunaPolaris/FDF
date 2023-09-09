/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:42:48 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/08 20:08:53 by fpolaris         ###   ########.fr       */
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
# define HGHT_SCL 1
# define SCALE 4

typedef struct s_wireframe
{
	t_vector	vertice;
	int		color;
	struct s_wireframe	*xplus;
	struct s_wireframe	*xmins;
	struct s_wireframe	*yplus;
	struct s_wireframe	*ymins;
}	t_wireframe;

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

t_wireframe	**fp_new_frame(int max_x, int max_y);
void		fp_erase_frame(t_wireframe **grid, int max_x);

void	fp_putpixel(t_mlx *data, int x, int y, int color);
void	fp_putvertice(t_mlx *data, t_vector *vertx, int quantity, int color);
void	fp_putline(t_mlx *data, t_vector point_a, t_vector point_b);

t_vector	*fp_rect(int width, int height, int depth);

void	fp_set_all(t_mlx *data, int color);

t_vector	fp_isometric(const t_vector vertx);
t_vector	fp_find_center(void);
double		fp_lerp(double v1, double v2, double t);
int		fp_lerpcolor(int color1, int color2, double t);

#endif
