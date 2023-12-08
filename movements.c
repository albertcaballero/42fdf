/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:19 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/08 01:27:40 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation(t_coord *coord, t_input input)
{
	float	angx;
	float	angy;
	float	angz;
	float	temp;

	angx = (30 + input.rotx) * M_PI / 180;
	angy = (-30 + input.roty) * M_PI / 180;
	angz = (30 + input.rotz) * M_PI / 180;
	temp = coord->y;
	coord->y = coord->y * cos(angx) - sin (angx) * coord->z;
	coord->z = temp * sin(angx) + cos(angx) * coord->z;
	temp = coord->x;
	coord->x = coord->x * cos(angy) + sin(angy) * coord->z;
	coord->z = -temp * sin(angy) + coord->z * cos(angy);
	temp = coord->x;
	coord->x = coord->x * cos(angz) - coord->y * sin(angz);
	coord->y = temp * sin(angz) + cos(angz) * coord->y;
}

void	scale(t_coord *coord, t_input input)
{
	if (input.zoom == 0)
		input.zoom++;
	coord->x = coord->x * (5 + input.zoom);
	coord->y = coord->y * (5 + input.zoom);
}

void	translation(t_coord *coord, t_input input)
{
	coord->x += 300 + input.mvx;
	coord->y += 300 + input.mvy;
}

void	start_draw_coord(t_coord *point, t_coord ini, t_input input)
{
	*point = ini;
	if (input.height == 0)
		input.height++;
	point->z /= input.height;
	rotation(point, input);
	scale(point, input);
	translation(point, input);
}
