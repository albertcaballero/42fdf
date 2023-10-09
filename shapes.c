/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:16 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/09 15:24:36 by alcaball         ###   ########.fr       */
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
	while (iy < size.h + yst)
	{
		ix = xst;
		while (ix < size.w + xst)
		{
			if (ix == xst || ix == size.w + xst - 1 || iy == yst || iy == size.h + yst - 1)
				my_mlx_pixel_put(img, ix, iy, color);
			ix++;
		}
		iy++;
	}

}

void	grid(t_data *img, t_dim win, int *values)
{
	int		vert;
	int		horiz;
	t_dim	dim;
	int		col;

	vert = 0;
	dim.w = 20;
	dim.h = 20;
	col = 0;
	while (vert < win.h)
	{
		horiz = 0;
		while (horiz < win.w)
		{
			if (values[col] > 0)
				square(img, dim, 100 + dim.w * horiz, 100 + dim.h * vert, 0x00FF0000);
			else
				square(img, dim, 100 + dim.w * horiz, 100 + dim.h * vert, 0x0000FF00);
			horiz++;
			col++;
		}
		vert++;
	}
}

void	circle(t_data *img, int h)
{
	int	ix;
	int	iy;
	int	ii;

	iy = 0;
	ii = 0;
	while (iy < 400)
	{
		ix = 0;
		while (ix < 400)
		{
			if (pow((ix - 200), 2) + pow((iy - 200), 2) == pow(h / 2, 2))
			{
				my_mlx_pixel_put(img, ix, iy, 0x0000FF00);
				ft_printf("%i, %i ||", ix, iy);
				ii++;
			}
			ix++;
		}
		iy++;
	}
	ft_printf("%i", ii);

}
