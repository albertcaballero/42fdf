/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:16 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/08 00:21:24 by albert           ###   ########.fr       */
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

t_coord	*update_coordinate_grid(t_coord *initial, long mapsz, t_input keys)
{
	t_coord *values;
	int		i;

	i = 0;
	values = malloc(sizeof(t_coord) * mapsz);
	while (i < mapsz)
	{
		values[i] = start_draw_coord(initial[i], keys);
		i++;
	}
	return (values);
}

void	grid(t_mlx *mlx, t_map map)
{
	t_coord *up_val;
	int		i;

	i = 0;
	map.max = max_value(mlx->ini, map, MAX); //esto fuera al main
	map.min = max_value(mlx->ini, map, MIN); //esto tb
	up_val = update_coordinate_grid(mlx->ini, map.count, mlx->keys);
	while (i < map.count)
	{
		if ((i + 1) % (int)map.x != 0)
			line(&mlx->img, up_val[i], up_val[i + 1], map);
		if (i / (int)(map.x) + 1 < map.y)
			line(&mlx->img, up_val[i], up_val[i + (int)map.x], map);
		i++;
	}
	free(up_val);
	//having 4 fcking functions to draw a single fckng line maybe is not the best way, but idk not an expert
}
