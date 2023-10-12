/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:19 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/12 17:17:03 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	rotation(t_coord coord)
{
	float	angle;

	angle = 0;
	coord.x = coord.x * cos(angle) - coord.y * sin(angle);
	coord.y = coord.x * sin(angle) + coord.y * cos(angle);
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
