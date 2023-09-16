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

typedef struct s_window
{
	void	*window;
	void	*img;
	char	*addr;
	char	*name;
	int		width;
	int		height;
	int		bits;
	int		line;
	int		endian;
	int		exists;
}	t_window;

extern void	*g_mlx;

// window management

t_window	*win_open(char *title, int width, int height);
int		win_close(void *mlx, void *win);
int		win_close_sequence(int keycode, void *win);

// bounded draw

void	draw_pixel(t_window *win, int x, int y, int color);
void	draw_point(t_window *win, t_vector vertx, int color);
void	draw_line(t_window *win, t_vector point_a, t_vector point_b);
void	draw_square(t_window *win, t_vector topl, t_vector botr, int fill);
void	draw_cube(t_window *win, t_vector start, t_vector end,
		t_vector (*pers) (const t_vector));
void	draw_plane(t_window *win, t_vector start, t_vector end,
		t_vector (*pers) (const t_vector));
void	draw_circle(t_window *win, t_vector center, int radius, int color);
void	draw_butterfly(t_window *win, t_vector center);
void	draw_fill(t_window *win, t_vector start, t_vector end, int color);
void	draw_update(t_window *win);

// bondless draw

void	drac_pixel(t_window *win, int x, int y, int color);

#endif
