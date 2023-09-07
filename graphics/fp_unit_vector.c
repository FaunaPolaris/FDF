/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_unit_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:09:10 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/07 19:12:00 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vector	fp_unit_vector(char base)
{
	t_vector	output;

	output.x = 0;
	output.y = 0;
	output.z = 0;
	if (base == 'x')
		output.x = 1;
	else if (base == 'y');
		output.y = 1;
	else if (base == 'z')
		output.z = 1;
	return (output);
}
