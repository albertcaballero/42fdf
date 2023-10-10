/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:18:47 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/10 19:11:19 by alcaball         ###   ########.fr       */
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

t_coord	get_point_coord(int *values, int i, t_dim win)
{
	t_coord	coord;

	coord.y = (int)round(i / (int)(win.x)) * (250 / win.y) + 50 + 15*(int)round(i % (int)(win.x));
	coord.x = (int)round(i % (int)(win.x)) * (450 / win.x) + 250 - 20*(int)round(i / (int)(win.x));

	coord.z = values[i];
	coord.x = coord.x + coord.z * (sqrt(3) / 2);
	coord.y = coord.y - coord.z * 0.5;
	return (coord);
} //angle between lines: v1=(230,72)-(250, 50)  v2=(273,65)-(250,50) SCREENSHOT

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
