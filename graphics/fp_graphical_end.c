/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_graphical_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:26:23 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/08 19:08:44 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

void	fp_graphical_end(t_mlx *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
		free(data->mlx);
}
