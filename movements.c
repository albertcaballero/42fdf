/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:19 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/14 21:43:04 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	rotation(t_coord coord, t_input input)
{
	float	angx;
	float	angy;
	float	angz;
	float	temp;

	angx = (45 + input.rotx) * M_PI / 180;
	angy = (-30 + input.roty) * M_PI / 180;
	angz = (30 + input.rotz) * M_PI / 180;
	temp = coord.y;
	coord.y = coord.y * cos(angx) - sin (angx) * coord.z;
	coord.z = temp * sin(angx) + cos(angx) * coord.z;
	temp = coord.x;
	coord.x = coord.x * cos(angy) + sin(angy) * coord.z;
	coord.z = -temp * sin(angy) + coord.z * cos(angy);
	temp = coord.x;
	coord.x = coord.x * cos(angz) - coord.y * sin(angz);
	coord.y = temp * sin(angz) + cos(angz) * coord.y;
	return (coord);
}

t_coord	scale(t_coord coord, t_input input)
{
	coord.x = coord.x * (10 + input.zoom);
	coord.y = coord.y * (10 + input.zoom);
	return (coord);
}

t_coord	translation(t_coord coord, t_input input)
{
	coord.x += 300 + input.mvx;
	coord.y += 400 + input.mvy;
	return (coord);
}

t_coord	start_draw_coord(t_coord point, t_input input)
{
	t_coord	copy;

	copy = point;
	input = init_input(input);
	copy.z /= input.height;
	copy = rotation(copy, input);
	copy = scale(copy, input);
	copy = translation(copy, input);
	return (copy);
}
