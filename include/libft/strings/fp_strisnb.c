/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_strisnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:05:22 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/13 15:05:23 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fp_strisnb(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!fp_isdigit(str[i]))
			return (0);
	}
	return (1);
}
