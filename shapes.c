/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:16 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/12 14:22:38 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_data *img, int startx, int starty, int endx, int endy)
{
	float	ix;
	float	iy;
	float	grad;

	ix = 0;
	iy = 0;
	if (abs(endx - startx) > abs(endy - starty))
	{
		grad = (float)(endy - starty) / (float)(endx - startx);
		iy = starty;
		while (ix < abs(endx - startx))
		{
			my_mlx_pixel_put(img, ix + startx, (int)round(iy), 0x00FFFFFF);
			ix++;
			iy += grad;
		}
	}
	else
	{
		grad = (float)(endx - startx) / (float)(endy - starty);
		ix = startx;
		while (iy < abs(endy - starty))
		{
			my_mlx_pixel_put(img, (int)round(ix), iy + starty, 0x00FFFFFF);
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
	int		i;

	i = 0;
	while (i < win.x * win.y)
	{
		point = start_draw_coord(values[i], win);
		next = start_draw_coord(values[i + 1], win);
		my_mlx_pixel_put(img, point.x, point.y, 0x0000FF00);
		if ((i + 1) % (win.x) != 0)
			line(img, point.x, point.y, next.x, next.y);
		if ((i) / (int)(win.x) + 1 < win.y)
		{
			lower = start_draw_coord(values[i + win.x], win);
			line(img, point.x, point.y, lower.x, lower.y);
		}
		i++;
	}
}
