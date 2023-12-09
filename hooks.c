/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:42:40 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/09 17:09:30 by alcaball         ###   ########.fr       */
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
	inp.zoom = 9;
	inp.line = 0;
	return (inp);
}

t_input	rotation_hooks(int key, t_input transf)
{
	if (key == LEFT)
		transf.rotz -= 10;
	else if (key == RIGHT)
		transf.rotz += 10;
	else if (key == UP)
		transf.rotx += 10;
	else if (key == DOWN)
		transf.rotx -= 10;
	else if (key == K_7)
		transf.roty -= 10;
	else if (key == K_9)
		transf.roty += 10;
	return (transf);
}

t_input	movement_hooks(int key, t_input transf)
{
	if (key == K_W)
		transf.mvy -= 10;
	else if (key == K_S)
		transf.mvy += 10;
	else if (key == K_A)
		transf.mvx -= 10;
	else if (key == K_D)
		transf.mvx += 10;
	return (transf);
}

t_input	zoom_hooks(int key, t_input transf)
{
	if (key == DIV)
		transf.height -= 1;
	else if (key == MULT)
		transf.height += 1;
	else if (key == K_MEN)
		transf.zoom -= 2;
	else if (key == K_PLUS)
		transf.zoom += 2;
	return (transf);
}

int	register_hooks(int key, t_mlx *mlx)
{
	if (key == ESC)
		close_program(mlx);
	else if (key == LEFT || key == RIGHT || key == UP \
				|| key == DOWN || key == K_7 || key == K_9)
		mlx->keys = rotation_hooks(key, mlx->keys);
	else if (key == K_W || key == K_A || key == K_S || key == K_D)
		mlx->keys = movement_hooks(key, mlx->keys);
	else if (key == DIV || key == MULT || key == K_MEN || key == K_PLUS)
		mlx->keys = zoom_hooks(key, mlx->keys);
	else if (key == SPA)
	{
		mlx->keys.line++;
		if (mlx->keys.line > 2)
			mlx->keys.line = 0;
	}
	else
		return (0);
	clear_screen(&mlx->img);
	grid(mlx, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}
