/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:18:47 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/10 16:48:12 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char *gnline, char **splited)
{
	int	i;

	i = 0;
	if (gnline)
		free(gnline);
	while (splited[i] != NULL)
	{
		free(splited[i]);
		i++;
	}
	free (splited);
}

t_dim	get_point_coord(int *values, int i, t_dim win)
{
	t_dim	coord;
	(void) values;
	coord.y = (int)round(i / (int)(win.x)) * (250 / win.y) + 50 + 20*(int)round(i % (int)(win.x));
	coord.x = (int)round(i % (int)(win.x)) * (450 / win.x) + 250 - 20*(int)round(i / (int)(win.x));

	// coord.z = values[i];
	// coord.x = coord.x - coord.z * (sqrt(3) / 2);
	// coord.y = coord.y - coord.z * 0.5;
	return (coord);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
