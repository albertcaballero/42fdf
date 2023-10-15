/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:30:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/15 16:53:50 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	win_size(t_map map)
{
	int		columns;
	char	*line;

	map.fd = open(map.argv, R_OK);
	if (map.fd < 0)
		return (map.x = 0, map);
	line = get_next_line(map.fd);
	map.x = map_length(line);
	if (map.x == 0)
		return (map.x = 0, map);
	columns = 1;
	while (line != NULL)
	{
		free (line);
		line = get_next_line(map.fd);
		if (map_length(line) != map.x && map_length(line) != 0)
			return (map.x = 0, map);
		columns++;
	}
	free(line);
	map.y = columns - 1;
	close(map.fd);
	return (map);
}

t_coord	init_coordinates(char *splitted, t_coord value, t_map mapdim, int i)
{
	value.x = (float)(i % (int)mapdim.x) *2;
	value.y = (float)(i / (int)mapdim.x) *2;
	value.z = ft_atoi(splitted);
	value.h = value.z;
	return (value);
}

t_coord	*read_map(t_map map, int i)
{
	t_coord	*values;
	char	*line;
	char	**splited;
	int		j;

	map.fd = open(map.argv, R_OK);
	if (map.fd < 0)
		return (NULL);
	values = malloc (sizeof(t_coord) * map.x * map.y);
	if (!values)
		return (NULL);
	line = get_next_line(map.fd);
	while (line != NULL)
	{
		j = -1;
		splited = ft_split(line, ' ');
		while (splited[++j] != NULL)
		{
			values[i] = init_coordinates(splited[j], values[i], map, i);
			i++;
		}
		ft_free(line, splited);
		line = get_next_line(map.fd);
	}
	return (free(line), close(map.fd), values);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
		return (0);
	mlx.map.argv = argv[1];
	mlx.map = win_size(mlx.map);
	if (mlx.map.x == 0)
		return (write(2, "invalid map", 11));
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_W, WIN_H, "FDF");
	mlx.img.img = mlx_new_image(mlx.mlx, WIN_W, WIN_H);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bpp, \
		&mlx.img.line_length, &mlx.img.endian);
	mlx.keys = init_input(mlx.keys);
	mlx_key_hook(mlx.win, register_hooks, &mlx);
	grid(&mlx, mlx.map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, CLOSE, 0, close_program, (&mlx));
	mlx_loop(mlx.mlx);
	return (0);
}
