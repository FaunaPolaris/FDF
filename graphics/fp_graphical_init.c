/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_graphical_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:00:36 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/07 19:13:15 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_mlx	*fp_graphical_init(char *title)
{
	t_mlx	*mlx_data;

	mlx_data = (t_mlx *)malloc(sizeof(t_mlx));
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		return (mlx_data);
	mlx_data->window = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, title);
	if (!mlx_data->window)
		return (mlx_data);
	return (mlx_data);
}
