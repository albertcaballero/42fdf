/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:53:21 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/13 17:07:28 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max_value(t_coord *values, t_coord map, int flag)
{
	int	i;
	int	max;

	i = 0;
	max = values[0].h;
	if (flag == MAX)
	{
		while (i < map.y * map.x)
		{
			if (values[i].h > max)
				max = values[i].h;
			i++;
		}
	}
	else if (flag == MIN)
	{
		while (i < map.y * map.x)
		{
			if (values[i].h < max)
				max = values[i].h;
			i++;
		}
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

	if (len == 0)
		len = 1;
	cpp.r = (endcolor.r - start.r) / len;
	cpp.g = (endcolor.g - start.g) / len;
	cpp.b = (endcolor.b - start.b) / len;
	rgb.r = abs(start.r + (cpp.r * i));
	rgb.g = abs(start.g + cpp.g * i);
	rgb.b = abs(start.b + cpp.b * i);
	rgb = rgb_calc(rgb, ADD);
	return (rgb);
}

t_colors	relative_color(int max, t_coord point, t_colors final)
{
	t_colors	color;
	float		percent;

	if (max != 0)
		percent = point.h / max;
	else
		percent = 1;
	color.r = percent * final.r;
	color.g = percent * final.g;
	color.b = percent * final.b;
	color = rgb_calc(color, ADD);
	if (point.h == 0)
		return (final);
	return (color);
}

int	colors(t_coord point, t_coord next, int i, int max)
{
	t_colors	final;
	t_colors	start;
	t_colors	color;
	int			len;

	final.all = BLUE;
	final = rgb_calc(final, DIVIDE);
	start.all = YELLOW;
	start = rgb_calc(start, DIVIDE);
	len = fabs(point.h - next.h);
	// if (len == 0)
	// 	color = relative_color(max, point, final);
	// else
	color = gradient(final, start, len, i);
	//get color point (based on height)
	// get color next (based on height)
	//gradient between both colors omg so stupid
	return (color.all);
}
