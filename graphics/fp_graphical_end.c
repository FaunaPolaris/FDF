/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_graphical_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:26:23 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/07 19:46:59 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

void	fp_graphical_end(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->window);
	free(data->mlx);
	free(data);
}
