/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:42:40 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/14 21:52:01 by albert           ###   ########.fr       */
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
		transf.zoom += 10;
	return (transf);
}

int	register_hooks(int key, t_input input)
{
	ft_printf("%i\n", key);
	if (key == ESC)
	{
		//FREE ALL
		exit(EXIT_SUCCESS);
	}
	else if (key == K || key == L || key == I || key ==  M || key == U || key == O)
		input = rotation_hooks(key, input);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT || key == V || key == B)
		input = movement_hooks(key, input);
	else
		return (0);
	return (0);
}
