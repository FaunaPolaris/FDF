/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:42:48 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/07 19:07:31 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHLIB_H
#define GRAPHLIB_H

# include <mlx.h>
# include <stdlib.h>

# ifndef WIDTH
# define WIDTH 1280
# endif

# ifndef HEIGHT
# define HEIGHT 720
# endif

typedef struct s_vector
{
	int	x;
	int	y;
	int	magnitude;
	int	direction;
}	t_vector;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits;
	int		line_lenght;
	int		endian;
}	t_img_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

t_mlx	*fp_graphical_init(char *title);
void	fp_graphical_end(t_mlx *data);

#endif
