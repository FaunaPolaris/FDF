/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_find_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:55:53 by fpolaris          #+#    #+#             */
/*   Updated: 2023/08/09 09:36:29 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vector	fp_find_center(void)
{
	t_vector	output;

	output.x = WIDTH / 2;
	output.y = HEIGHT / 2;
	return(output);
}
