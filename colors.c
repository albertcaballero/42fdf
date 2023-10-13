/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:53:21 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/13 14:41:20 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max_value(t_coord *values, t_coord map)
{
	int	i;
	int	max;

	i = 0;
	max = values[0].h;
	while (i < map.y * map.x)
	{
		if (values[i].h > max)
			max = values[i].h;
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

t_colors	gradient(t_colors endcolor, t_colors start, int len, int i)
{
	t_colors	rgb;
	t_colors	cpp;

	cpp.r = (endcolor.r - start.r) / len;
	cpp.g = (endcolor.g - start.g) / len;
	cpp.b = (endcolor.b - start.b) / len;
	rgb.r = abs(start.r + (cpp.r * i));
	rgb.g = abs(start.g + cpp.g * i);
	rgb.b = abs(start.b + cpp.b * i);
	rgb = rgb_calc(rgb, ADD);
	return (rgb);
}

t_colors	relative_color(int max, t_coord point, t_coord next)
{
	t_colors	color;
	float		diff;

	diff = point.h - next.h;
}

int	colors(t_coord point, t_coord next, int i, int max)
{
	t_colors	final;
	t_colors	start;
	t_colors	relstart;
	t_colors	color;
	int			len;

	final.all = BLUE;
	final = rgb_calc(final, DIVIDE);
	start.all = YELLOW;
	start = rgb_calc(start, DIVIDE);
	relstart = start;
	relstart = relative_color(max, point, next);
	if (fabs(point.x - next.x) > fabs(point.y - next.y))
		len = fabs(point.x - next.x);
	else
		len = fabs(point.y - next.y);
	color = gradient(final, start, len, i);
	if (point.h == next.h)
		color.all = 
	return (color.all);
}
