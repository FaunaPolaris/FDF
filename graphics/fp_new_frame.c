/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_new_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:54:34 by fpolaris          #+#    #+#             */
/*   Updated: 2023/09/07 18:50:17 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

static void	st_relate_center(t_wireframe **grid, int max_x, int max_y);
static void	st_relate_sides(t_wireframe **grid, int max_x, int max_y);
static void	st_fill_positions(t_wireframe **grid, int max_x, int max_y);

t_wireframe	**fp_new_frame(int max_x, int max_y)
{
	t_wireframe	**grid;
	int		i;

	grid = (t_wireframe **)fp_calloc(max_x, sizeof(t_wireframe *));
	i = 0;
	while (i < max_x)
	{
		grid[i] = (t_wireframe *)fp_calloc(max_y, sizeof(t_wireframe));
		i++;
	}
	st_relate_center(grid, max_x, max_y);
	st_relate_sides(grid, max_x, max_y);
	st_fill_positions(grid, max_x, max_y);
	return (grid);
}

void	fp_erase_frame(t_wireframe **grid, int max_x)
{
	int	x;

	x = 0;
	while (x < max_x)
	{
		free(grid[x]);
		x++;
	}
	free(grid);
}

static void	st_relate_center(t_wireframe **grid, int max_x, int max_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < max_x)
	{
		y = 0;
		while (y < max_y)
		{
			if (x != max_x - 1)
				grid[x][y].xplus = &grid[x + 1][y];
			if (x != 0)
				grid[x][y].xmins = &grid[x - 1][y];
			if (y != max_y - 1)
				grid[x][y].yplus = &grid[x][y + 1];
			if (y != 0)
				grid[x][y].ymins = &grid[x][y - 1];
			y++;
		}
		x++;
	}
}

static void	st_relate_sides(t_wireframe **grid, int max_x, int max_y)
{
	int	i;

	i = 0;
	while (i < max_y)
	{
		grid[0][i].xmins = &grid[max_x - 1][i];
		grid[max_x - 1][i].xplus = &grid[0][i];
		i++;
	}
	i = 0;
	while (i < max_x)
	{
		grid[i][0].ymins = &grid[i][max_y - 1];
		grid[i][max_y - 1].yplus = &grid[i][0];
		i++;
	}
}

static void	st_fill_positions(t_wireframe **grid, int max_x, int max_y)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = -max_x / 2;
	i = -1;
	while (++i < max_x)
	{
		j = -1;
		y = -max_y / 2;
		while (++j < max_y)
		{
			grid[i][j].vertice.x = x * SCALE;
			grid[i][j].vertice.y = y * SCALE;
			grid[i][j].color = 0x00BB99;
			y++;
		}
		x++;
	}
}
