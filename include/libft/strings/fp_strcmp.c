/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:20:07 by fpolaris          #+#    #+#             */
/*   Updated: 2023/10/13 15:20:08 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fp_strcmp(char *str1, char *str2)
{
	int	i;

	i = -1;
	while (str1[++i] && str2[i] && str1[i] == str2[i])
		;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
