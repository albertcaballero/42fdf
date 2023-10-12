/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:18:47 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/12 17:11:45 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_length(char	*line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!line)
		return (0);
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

t_coord	start_draw_coord(t_coord point, t_coord win)
{
	(void) win;
	point = scale(point);
	point = rotation(point);
	point = translation(point);
	return (point);
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
