/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:53:21 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/15 16:20:32 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max_value(t_coord *values, t_map map, int flag)
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

t_colors	relative_color(t_map map, t_coord point, t_colors fin, t_colors st)
{
	t_colors	color;
	float		fpercent;

	if ((map.max) != 0)
		fpercent = fabs(point.h) / (map.max);
	else
		fpercent = 0;
	color.r = fpercent * fin.r + (1 - fpercent) * st.r;
	color.g = fpercent * fin.g + (1 - fpercent) * st.g;
	color.b = fpercent * fin.b + (1 - fpercent) * st.b;
	color = rgb_calc(color, ADD);
	return (color);
}

int	colors(t_coord point, t_coord next, int i, t_map map)
{
	t_colors	final;
	t_colors	start;
	t_colors	relstart;
	t_colors	relfinal;
	int			len;

	final.all = YELLOW;
	final = rgb_calc(final, DIVIDE);
	start.all = BLUE;
	start = rgb_calc(start, DIVIDE);
	if (fabs(point.x - next.x) > fabs(point.y - next.y))
		len = fabs(point.x - next.x);
	else
		len = fabs(point.y - next.y);
	relstart = relative_color(map, point, final, start);
	relfinal = relative_color(map, next, final, start);
	start = gradient(relfinal, relstart, len, i);
	return (start.all);
}
