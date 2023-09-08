/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:09:59 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/08 16:33:03 by fpolaris         ###   ########.fr       */
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
	mlx_key_hook(data->mlx->window, st_handle_rot, data);

}
