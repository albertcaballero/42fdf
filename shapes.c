/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:16 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/07 00:00:43 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	horiz_backline(t_data *img, t_coord start, t_coord end, t_map map)
{
	float	ix;
	float	iy;
	float	grad;

	ix = 0;
	grad = (float)(end.y - start.y) / (float)fabs(end.x - start.x);
	iy = start.y;
	while (ix < fabs(end.x - start.x))
	{
		my_mlx_pixel_put(img, -ix + start.x, (int)round(iy), \
			colors(start, end, ix, map));
		ix++;
		iy += grad;
	}
}

void	vert_backline(t_data *img, t_coord start, t_coord end, t_map map)
{
	float	ix;
	float	iy;
	float	grad;

	iy = 0;
	grad = (float)(end.x - start.x) / (float)fabs(end.y - start.y);
	ix = start.x;
	while (iy < fabs(end.y - start.y))
	{
		my_mlx_pixel_put(img, (int)round(ix), -iy + start.y, \
			colors(start, end, iy, map));
		iy++;
		ix += grad;
	}
}

void	vert_frontline(t_data *img, t_coord start, t_coord end, t_map map)
{
	float	ix;
	float	iy;
	float	grad;

	iy = 0;
	if (end.y < start.y)
		return (vert_backline(img, start, end, map));
	grad = (float)(end.x - start.x) / (float)(end.y - start.y);
	ix = start.x;
	while (iy < fabs(end.y - start.y))
	{
		my_mlx_pixel_put(img, (int)round(ix), iy + start.y, \
			colors(start, end, iy, map));
		iy++;
		ix += grad;
	}
}

void	line(t_data *img, t_coord start, t_coord end, t_map map)
{
	float	ix;
	float	iy;
	float	grad;

	ix = 0;
	if (fabs(end.x - start.x) > fabs(end.y - start.y))
	{
		if (end.x < start.x)
			return (horiz_backline(img, start, end, map));
		grad = (float)(end.y - start.y) / (float)(end.x - start.x);
		iy = start.y;
		while (ix < fabs(end.x - start.x))
		{
			my_mlx_pixel_put(img, ix + start.x, (int)round(iy), \
				colors(start, end, ix, map));
			ix++;
			iy += grad;
		}
	}
	else
		vert_frontline(img, start, end, map);
}

void	grid(t_mlx *mlx, t_map map)
{
	t_coord	point;
	t_coord	next;
	t_coord	lower;
	t_coord	*values;
	int		i;

	i = 0;
	values = read_map(map, 0);
	map.max = max_value(values, map, MAX);
	map.min = max_value(values, map, MIN);
	while (i < map.x * map.y)
	{
		point = start_draw_coord(values[i], mlx->keys);
		next = start_draw_coord(values[i + 1], mlx->keys);
		if ((i + 1) % (int)map.x != 0)
			line(&mlx->img, point, next, map);
		if ((i) / (int)(map.x) + 1 < map.y)
		{
			lower = start_draw_coord(values[i + (int)map.x], mlx->keys);
			line(&mlx->img, point, lower, map);
		}
		// (void) lower; //ni idea de por que esta linea esta aqui
		i++;
	}
	free(values);
	//you're searching for start_draw_coord of each point 3 times, do that in a single matrix, and calculate it entirely
	//same as you have a read_map() or init_coordinates()

	//also having 4 fcking functions to draw a single fckng line maybe is not the best way, but idk not an expert
}
