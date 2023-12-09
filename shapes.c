/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:16 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/09 17:23:32 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//these line functs can still be optimized

void	vert_line(t_data *img, t_coord start, t_coord end, t_map map)
{
	float	ix;
	float	iy;
	float	grad;
	t_coord	tmp;

	iy = 0;
	if (end.y < start.y)
	{
		tmp = start;
		start = end;
		end = tmp;
	}
	grad = (float)(end.x - start.x) / (float)(end.y - start.y);
	ix = start.x;
	while (iy < end.y - start.y)
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
	t_coord	tmp;

	ix = 0;
	if (fabs(end.x - start.x) < fabs(end.y - start.y))
		return (vert_line(img, start, end, map));
	if (end.x < start.x)
	{
		tmp = start;
		start = end;
		end = tmp;
	}
	grad = (float)(end.y - start.y) / (float)(end.x - start.x);
	iy = start.y;
	while (ix < end.x - start.x)
	{
		my_mlx_pixel_put(img, ix + start.x, (int)round(iy), \
			colors(start, end, ix, map));
		ix++;
		iy += grad;
	}
}

t_coord	*update_coordinate_grid(t_coord *initial, long mapsz, t_input keys)
{
	t_coord	*values;
	int		i;

	i = 0;
	values = malloc(sizeof(t_coord) * mapsz);
	while (i < mapsz)
	{
		start_draw_coord(&values[i], initial[i], keys);
		i++;
	}
	return (values);
}

void	paint_points(t_data *img, t_coord *val, t_map map)
{
	int	i;

	i = 0;
	while (i < map.count)
	{
		if (val[i].clr == 0)
			val[i].clr = colors(val[i], val[i], 1, map);
		my_mlx_pixel_put(img, (int)round(val[i].x), \
			(int)round(val[i].y), val[i].clr);
		i++;
	}
}

void	grid(t_mlx *mlx, t_map map)
{
	t_coord	*val;
	int		i;

	i = 0;
	val = update_coordinate_grid(mlx->ini, map.count, mlx->keys);
	if (mlx->keys.line == 2)
	{
		paint_points(&mlx->img, val, map);
		return (free(val));
	}
	while (i < map.count)
	{
		if ((i + 1) % (int)map.x != 0 && mlx->keys.line == 0)
			line(&mlx->img, val[i], val[i + 1], map);
		if (i / (int)(map.x) + 1 < map.y)
			line(&mlx->img, val[i], val[i + (int)map.x], map);
		i++;
	}
	free(val);
}
