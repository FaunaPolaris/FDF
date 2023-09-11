/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_find_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:55:53 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/15 12:06:09 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vector	mtx_centerv(void)
{
	t_vector	output;

	output.x = WIDTH / 2;
	output.y = HEIGHT / 2;
	output.z = 1;
	return(output);
}
