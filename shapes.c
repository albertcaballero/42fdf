/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:16 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/13 14:30:02 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	horiz_backline(t_data *img, t_coord start, t_coord end, int max)
{
	float	ix;
	float	iy;
	float	grad;

	ix = 0;
	grad = (float)(end.y - start.y) / (float)fabs(end.x - start.x);
	iy = start.y;
	while (ix < fabs(end.x - start.x))
	{
		my_mlx_pixel_put(img, -ix + start.x, (int)round(iy), colors(start, end, ix, max));
		ix++;
		iy += grad;
	}
}

void	vert_backline(t_data *img, t_coord start, t_coord end, int max)
{
	float	ix;
	float	iy;
	float	grad;

	iy = 0;
	grad = (float)(end.x - start.x) / (float)fabs(end.y - start.y);
	ix = start.x;
	while (iy < fabs(end.y - start.y))
	{
		my_mlx_pixel_put(img, (int)round(ix), -iy + start.y, colors(start, end, iy, max));
		iy++;
		ix += grad;
	}
}

void	line(t_data *img, t_coord start, t_coord end, int max)
{
	float	ix;
	float	iy;
	float	grad;

	ix = 0;
	iy = 0;
	if (fabs(end.x - start.x) > fabs(end.y - start.y))
	{
		if (end.x < start.x)
			return (horiz_backline(img, start, end));
		grad = (float)(end.y - start.y) / (float)(end.x - start.x);
		iy = start.y;
		while (ix < fabs(end.x - start.x))
		{
			my_mlx_pixel_put(img, ix + start.x, (int)round(iy), colors(start, end, ix, max));
			ix++;
			iy += grad;
		}
	}
	else
	{
		if (end.y < start.y)
			return (vert_backline(img, start, end));
		grad = (float)(end.x - start.x) / (float)(end.y - start.y);
		ix = start.x;
		while (iy < fabs(end.y - start.y))
		{
			my_mlx_pixel_put(img, (int)round(ix), iy + start.y, colors(start, end, iy, max));
			iy++;
			ix += grad;
		}
	}
}

void	grid(t_data *img, t_coord win, t_coord *values)
{
	t_coord	point;
	t_coord	next;
	t_coord	lower;
	int		max;
	int		i;

	i = 0;
	max = max_value(values, win);
	while (i < win.x * win.y)
	{
		point = start_draw_coord(values[i]);
		next = start_draw_coord(values[i + 1]);
		my_mlx_pixel_put(img, point.x, point.y, GREEN);
		if ((i + 1) % (int)(win.x) != 0)
			line(img, point, next, max);
		if ((i) / (int)(win.x) + 1 < win.y)
		{
			lower = start_draw_coord(values[i + (int)win.x]);
			line(img, point, lower, max);
		}
		(void) lower;
		i++;
	}
}
