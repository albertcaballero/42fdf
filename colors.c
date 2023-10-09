/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:53:21 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/09 17:40:56 by alcaball         ###   ########.fr       */
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

int	colors(int value, int maxval)
{
	int	maxcol;
	int	color;

	maxcol = 16777215;
	color = (value * maxcol) / maxval + 100;
	return (color);
}