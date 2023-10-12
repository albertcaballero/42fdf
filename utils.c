/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:18:47 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/12 13:21:43 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_length(char	*line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != 0 && line[i] != 10)
	{
		if (line[i] != 32 && line[i + 1] == 32)
			j++;
		i++;
	}
	j++;
	return (j);
}

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

t_coord	start_draw_coord(int *values, int i, t_coord win)
{
	t_coord	coord;

	coord.y = (int)round(i / (win.x)) * (250 / win.y) + 50 + 5 * (i % (win.x));
	coord.x = (int)round(i % (win.x)) * (450 / win.x) + 250 - 20 * (i / (win.x));

	coord.z = values[i] * 3;
	coord.x = coord.x + coord.z * (sqrt(3) / 2);
	coord.y = coord.y - coord.z * 0.5;
	return (coord);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && y > 0 && y < WIN_H && x < WIN_W)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
