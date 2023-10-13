/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:42:40 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/13 17:06:20 by alcaball         ###   ########.fr       */
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
	inp.zoom = 1;
	return (inp);
}

int	register_hooks(int key, t_vars *mlx)
{
	t_input	transf;

	transf = init_input(transf);
	ft_printf("%i\n", key);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
