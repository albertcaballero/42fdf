/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:42:40 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/14 01:05:29 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_input	init_input(t_input inp)
{
	inp.height = 1;
	if (inp.height == 0)
		inp.height++;
	inp.mvx = 0;
	inp.mvy = 0;
	inp.rotx = 0;
	inp.roty = 0;
	inp.rotz = 0;
	inp.zoom = 0;
	return (inp);
}

t_input	rotation_hooks(int key, t_input transf)
{
	if (key == K)
		transf.rotz += 10;
	else if (key == L)
		transf.rotz -= 10;
	else if (key == I)
		transf.rotx += 10;
	else if (key == M)
		transf.rotx -= 10;
	else if (key == U)
		transf.roty += 10;
	else if (key == O)
		transf.roty -= 10;
	//add for height + -
	return (transf);
}

t_input	movement_hooks(int key, t_input transf)
{
	if (key == UP)
		transf.mvy -= 10;
	else if (key == DOWN)
		transf.mvy += 10;
	else if (key == LEFT)
		transf.mvx -= 10;
	else if (key == RIGHT)
		transf.mvx += 10;
	else if (key == V)
		transf.zoom -= 10;
	else if (key == B)
		transf.mvx += 10;
	return (transf);
}

int	register_hooks(int key, t_vars *mlx)
{
	t_input	transf;

	transf = init_input(transf);
	ft_printf("%i\n", key);
	if (key == ESC)
	{
		//FREE ALL
		exit(EXIT_SUCCESS);
	}
	if (key == K || key == L || key == I || key ==  M || key == U || key == O)
		transf = rotation_hooks(key, transf);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT || key == V || key == B)
		transf = movement_hooks(key, transf);
	//destroy window, redraw window
	return (0);
}
