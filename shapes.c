/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:16 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/09 17:53:00 by alcaball         ###   ########.fr       */
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

void	line(t_data *img, t_dim start, t_dim end)
{
	float	ix;
	float	iy;
	float	grad;

	ix = 0;
	iy = 0;
	grad = (float)abs(end.y - start.y) / (float)abs(end.x - start.x);
	if (abs(end.x - start.x) >= abs(end.y - end.y))
	{
		iy = start.y;
		while (ix < end.x + start.x)
		{
			my_mlx_pixel_put(img, ix + start.x, (int)round(iy), 0x0000FF00);
			ix++;
			iy += grad;
		}
	}
	else
	{
		ix = start.x;
		while (iy < end.y + start.y)
		{
			my_mlx_pixel_put(img, iy + start.y, (int)round(ix), 0x0000FF00);
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

	end.x = 25;
	end.y = 200;
	start.x = 400;
	start.y = 10;
	col = 0;
	maxval = max_value(values, win);
	line (img, start, end);
}
