/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:16 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/10 13:49:42 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	square(t_data *img, t_dim size, int xst, int yst, int color)
{
	int	ix;
	int	iy;
	int	col;

	iy = yst;
	col = 0;
	while (iy < size.y + yst)
	{
		ix = xst;
		while (ix < size.x + xst)
		{
			if (ix == xst || ix == size.x + xst - 1 || iy == yst || iy == size.y + yst - 1)
				my_mlx_pixel_put(img, ix, iy, color);
			ix++;
		}
		iy++;
	}

}

void	straight_line(t_data *img, int x, int starty, int endx, int endy)
{
	int	iy;

	iy = 0;
	(void) endx;
	while (iy < abs(endy - starty))
	{
		my_mlx_pixel_put(img, x, iy + starty, 0x0000FF00);
		iy++;
	}
	return ;
}

void	line(t_data *img, int startx, int starty, int endx, int endy)
{
	float	ix;
	float	iy;
	float	grad;

	ix = 0;
	iy = 0;
	if (endx - startx == 0 || endy - starty == 0)
		return (straight_line(img, startx, starty, endx, endy));
	if (abs(endx - startx) > abs(endy - starty))
	{
		grad = (float)(endy - starty) / (float)(endx - startx);
		iy = starty;
		while (ix < abs(endx - startx))
		{
			my_mlx_pixel_put(img, ix + startx, (int)round(iy), 0x0000FF00);
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
			my_mlx_pixel_put(img, (int)round(ix), iy + starty, 0x0000FF00);
			iy++;
			ix += grad;
		}
	}
}

void	grid(t_data *img, t_dim win, int *values)
{
	t_dim	end;
	t_dim	start;
	int		col;
	int		maxval;
	int		i;

	i = 0;
	start.x = 250;
	end.x = 600;
	start.y = 50;
	end.y = 300;
	col = 0;
	maxval = max_value(values, win);
	while (i < win.x)
	{
		line (img, start.x, start.x + (450/win.x), end.x, end.x + (250/win.y));
		i++;
	}
	line (img, 250, 50, 600, 300);
	line (img, 250, 50, 100, 200);
	line (img, 100, 200, 450, 450);
	line (img, 600, 300, 450, 450);
	// while (i < win.x - 1)
	// {
	// 	line (img, start, end);
	// 	i++;
	// 	start.x = end.x;
	// 	end.x = start.x + 10;
	// }
}
