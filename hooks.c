/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:42:40 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/15 16:28:05 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_input	init_input(t_input inp)
{
	inp.height = 1;
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
	if (key == K_4)
		transf.rotz -= 10;
	else if (key == K_6)
		transf.rotz += 10;
	else if (key == K_8)
		transf.rotx += 10;
	else if (key == K_2)
		transf.rotx -= 10;
	else if (key == K_7)
		transf.roty -= 10;
	else if (key == K_9)
		transf.roty += 10;
	return (transf);
}

t_input	movement_hooks(int key, t_input transf)
{
	if (key == UP)
		transf.mvy -= 5;
	else if (key == DOWN)
		transf.mvy += 5;
	else if (key == LEFT)
		transf.mvx -= 5;
	else if (key == RIGHT)
		transf.mvx += 5;
	return (transf);
}

t_input	zoom_hooks(int key, t_input transf)
{
	if (key == DIV)
		transf.height -= 1;
	else if (key == MULT)
		transf.height += 1;
	else if (key == K_MEN)
		transf.zoom -= 5;
	else if (key == K_PLUS)
		transf.zoom += 5;
	return (transf);
}

int	register_hooks(int key, t_mlx *mlx)
{
	if (key == ESC)
		close_program(mlx);
	else if (key == K_2 || key == K_4 || key == K_6 \
				|| key == K_7 || key == K_8 || key == K_9)
		mlx->keys = rotation_hooks(key, mlx->keys);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		mlx->keys = movement_hooks(key, mlx->keys);
	else if (key == DIV || key == MULT || key == K_MEN || key == K_PLUS)
		mlx->keys = zoom_hooks(key, mlx->keys);
	else
		return (0);
	clear_screen(&mlx->img);
	grid(mlx, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}
