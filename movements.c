/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:19 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/12 19:55:55 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	rotation(t_coord coord)
{
	float	angx;
	float	angy;
	float	angz;

	angx = 45 * M_PI / 180;
	angy = 45 * M_PI / 180;
	angz = 70 * M_PI / 180;
	//  coord.y = coord.y * cos(angx) - sin (angx) * coord.z;
	//  coord.z = coord.y * sin(angx) + cos(angx) * coord.z;

	//  coord.x = coord.x*cos(angy) + sin(angy)*coord.z;
	//  coord.z = -coord.x*sin(angy) + coord.z*cos(angy);

	coord.x = coord.x*cos(angz) - coord.y*sin(angz);
	coord.y = coord.x*sin(angz) + cos(angz)*coord.y;

	return (coord);
}

t_coord	scale(t_coord coord)
{
	coord.x = coord.x * 10;
	coord.y = coord.y * 10;
	return (coord);
}

t_coord	translation(t_coord coord)
{
	coord.x += 300;
	coord.y += 400;
	return (coord);
}

t_coord	start_draw_coord(t_coord point, t_coord win)
{
	(void) win;
	point = rotation(point);
	point = scale(point);
	point = translation(point);
	return (point);
}