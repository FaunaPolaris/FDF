/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:49:51 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/13 19:54:07 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	draw_pixel(t_window *win, int x, int y, int color)
{
	char	*position;

	if (!win->exists)
		return ;
	if (x > win->width - 1 || y > win->height - 1 || x < 0 || y < 0)
		return ;
	y = -y + win->height;
	position = win->addr + (y * win->line
			+ (x * win->bits / 8));
	*(unsigned int *)position  = color;
}

void	drac_pixel(t_window *win, int x, int y, int color)
{
	char	*position;

	if (!win->exists)
		return ;
	if (x > win->width - 1)
		draw_pixel(win, x - win->width, y, color);
	if (y > win->height - 1)
		draw_pixel(win, x, y - win->height, color);
	if (x < 0)
		draw_pixel(win, x + win->width, y, color);
	if (y < 0)
		draw_pixel(win, x, y + win->height, color);
	if (x > win->width - 1 || y > win->height - 1 || x < 0 || y < 0)
		return ;
	y = -y + win->height;
	position = win->addr + (y * win->line
			+ (x * win->bits / 8));
	*(unsigned int *)position  = color;
}
