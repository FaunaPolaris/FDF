/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_graphical_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:00:36 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/08 19:12:48 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

int	fp_graphical_init(char *title, t_mlx *mlx_data)
{
	t_img_data	*img_data;

	img_data = (t_img_data *)malloc(sizeof(t_img_data));
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		return (1);
	mlx_data->window = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, title);
	if (!mlx_data->window)
		return (1);
	img_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	img_data->addr = mlx_get_data_addr(
				img_data->img,&img_data->bits,
				&img_data->line, &img_data->endian);
	mlx_data->img = img_data;
	return (0);
}
