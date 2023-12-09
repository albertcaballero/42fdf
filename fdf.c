/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:30:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/09 19:44:08 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_and_close(char *line, int fd)
{
	if (line != NULL)
		free (line);
	close (fd);
}

void	win_size(t_map *map)
{
	int		columns;
	char	*line;
	int		len;

	map->fd = open(map->argv, R_OK);
	len = 0;
	if (map->fd < 0)
		return (map->x = 0, (void)len);
	line = get_next_line(map->fd);
	map->x = map_length(line);
	if (map->x == 0)
		return (free_and_close(line, map->fd));
	columns = 1;
	while (line != NULL)
	{
		free (line);
		line = get_next_line(map->fd);
		len = map_length(line);
		if (len != map->x && len != 0)
			return (map->x = 0, free_and_close(line, map->fd));
		columns++;
	}
	free(line);
	map->y = columns - 1;
	close(map->fd);
}

void	init_coordinates(char *line, t_coord *value, t_map map, int col)
{
	int		i;
	char	**splited;
	int		mapx;

	i = 0;
	mapx = (int)map.x;
	splited = ft_split(line, ' ');
	if (splited == NULL)
		return ;
	while (i < mapx)
	{
		value[i + col * mapx].x = (float)((i - mapx / 2) * 2);
		value[i + col * mapx].y = (float)((col - (int)map.y / 2) * 2);
		value[i + col * mapx].z = ft_atoi(splited[i]);
		value[i + col * mapx].h = value[i + col * mapx].z;
		value[i + col * mapx].clr = ft_atoi_base(ft_strchr(splited[i], ','));
		i++;
	}
	ft_free(NULL, splited);
}

t_coord	*read_map(t_map *map, int i)
{
	t_coord	*values;
	char	*line;
	int		col;

	map->fd = open(map->argv, R_OK);
	if (map->fd < 0)
		return (NULL);
	values = malloc (sizeof(t_coord) * map->count);
	if (!values)
		return (NULL);
	line = get_next_line(map->fd);
	col = 0;
	while (line != NULL)
	{
		init_coordinates(line, values, *map, col);
		free(line);
		line = get_next_line(map->fd);
		col++;
		ft_printf("\tLoading map, please wait... %i/%i\r", col, (int)map->y);
	}
	ft_printf("\33[2K");
	return (free_and_close(line, map->fd), values);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (write(2, "invalid params\n", 16), 1);
	mlx.map.argv = argv[1];
	win_size(&mlx.map);
	if (mlx.map.x == 0)
		return (write(2, "invalid map\n", 12));
	mlx.map.count = mlx.map.x * mlx.map.y;
	mlx.ini = read_map(&mlx.map, 0);
	mlx.map.max = max_value(mlx.ini, mlx.map, MAX);
	mlx.map.min = max_value(mlx.ini, mlx.map, MIN);
	print_movements();
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_W, WIN_H, "FDF");
	mlx.img.img = mlx_new_image(mlx.mlx, WIN_W, WIN_H);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bpp, \
		&mlx.img.line_length, &mlx.img.endian);
	mlx.keys = init_input(mlx.keys);
	mlx_hook(mlx.win, 2, 0, register_hooks, &mlx);
	grid(&mlx, mlx.map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, CLOSE, 0, close_program, (&mlx));
	mlx_loop(mlx.mlx);
	return (0);
}
