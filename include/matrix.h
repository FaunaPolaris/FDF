/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:32:08 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/13 13:10:25 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <math.h>
# include "libft.h"

typedef struct s_constants
{
	double	cos_p45;
	double	sin_n30;
}	t_constants;

typedef struct s_vector
{
	double	y;
	double	x;
	double	z;
	int	color;
}	t_vector;

typedef struct s_ivector
{
	int	y;
	int	x;
	int	z;
}	t_ivector;

typedef struct s_matrix
{
	int	col;
	int	row;
	int	size;
	double	**elem;
}	t_matrix;

t_constants	*mtx_init(void);

t_matrix	mtx_new(int col, int row);
t_matrix	mtx_identity(int size);
t_matrix	mtx_from_vec(t_vector v, int col);
t_matrix	mtx_rotate(char axes, double angle);

t_vector	vec_new(double y, double x, double z, int color);
t_vector	vec_from_mtx(t_matrix m);
t_vector	vec_center(void);

t_matrix	mtx_multiply(const t_matrix a, const t_matrix b);
int		mtx_fill(t_matrix *m, char *content);
void		mtx_print(t_matrix m);

t_vector	vec_isometry(t_constants *mtx, const t_vector v);

void		mtx_free(t_matrix m);
t_matrix	mtx_null(void);
void	mtx_nullv(t_vector *m);

#endif
