/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:09:59 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/08 20:05:02 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

int	main(int argc, char **argv)
{
	t_fdfdata	*data;
	t_mlx		mlx;

	if (argc != 2)
		return (1);
	if (fp_graphical_init(&mlx))
		return (1);
	data->mlx = &mlx;
	mlx_key_hook(data->mlx->window, st_handle_keys, data);
	mtx_identity3(data->matrix);
	fdf_draw_map(data->grid, data, fp_isometric);
	mlx_loop(data->mlx->mlx);
	fp_graphical_end(&mlx)
	fp_erase_frame(data->grid);
}

static int	st_handle_keys(int keycode, void *param)
{
	t_fdfdata	*data;
	t_wireframe	**grid;

	fp_printf("handle event: %i\n", keycode);
	data = (t_fdfdata *)param;
	grid = data->grid;
	if (keycode == KEY_Q)
		data->matrix = mtx_multiply3d(data->matrix, mtx_rotate('x', 5));
	fp_set_all(data->mlx, 0x000000);
	fdf_draw_map(grid, data, fp_isometric);
}
