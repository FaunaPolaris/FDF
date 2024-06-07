/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:03:41 by fpolaris          #+#    #+#             */
/*   Updated: 2023/05/14 14:21:06 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fp_putnbr_fd(int n, int fd)
{
	int	output;

	output = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		output = fp_putchar_fd('-', fd);
	}
	if (n > 9)
	{
		output = fp_putnbr_fd(n / 10, fd);
		output = fp_putnbr_fd(n % 10, fd);
	}
	if (n <= 9)
		output = fp_putchar_fd(n + 48, fd);
	return (output);
}
