/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:19 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/12 14:18:22 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	rotation(t_coord coord)
{
	int	angle;

	angle = 30;
	(void) coord;
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
	coord.x += 100;
	coord.y += 100;
	return (coord);
}
