/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:53:21 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/13 13:56:26 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max_value(int *values, t_dim mapsize)
{
	int	i;
	int	max;

	i = 0;
	max = values[0];
	while (i < mapsize.y * mapsize.x)
	{
		if (values[i] > max)
			max = values[i];
		i++;
	}
	return (max);
}

t_colors	rgb_calc(t_colors color, int flag)
{
	if (flag == DIVIDE)
	{
		color.r = color.all >> 16;
		color.g = color.all >> 8 & 0xFF;
		color.b = color.all & 0xFF;
	}
	else
		color.all = (color.r << 16) + (color.g << 8) + color.b;
	return (color);
}

t_colors	gradient(t_colors endcolor, int len, int i)
{
	t_colors	rgb;
	t_colors	cpp;

	cpp.r = (endcolor.r - 0xFF) / len;
	cpp.g = (endcolor.g - 0xFF) / len;
	cpp.b = (endcolor.b - 0xFF) / len;
	rgb.r = abs(0xFF + (cpp.r * i));
	rgb.g = abs(0xFF + cpp.g * i);
	rgb.b = abs(0xFF + cpp.b * i);
	rgb = rgb_calc(rgb, ADD);
	return (rgb);
}


int	colors(t_coord point, t_coord next, int i)
{
	t_colors	final;
	t_colors	color;
	int			len;

	final.all = SPRING;
	final = rgb_calc(final, DIVIDE);
	len = fabs(point.x - next.x);
	color = gradient(final, len, i);
	if (point.h <= 0 && next.h == point.h) //tiene que depender de h y de maxval
		color.all = SPRING;
	return (color.all);
}
