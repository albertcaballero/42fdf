/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:30:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/13 17:40:45 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	win_size(char *argv)
{
	t_coord	window;
	int		fd;
	int		columns;
	char	*line;

	fd = open(argv, R_OK);
	if (fd < 0)
		return (window.x = 0, window);
	line = get_next_line(fd);
	window.x = map_length(line);
	if (window.x == 0)
		return (window.x = 0, window);
	columns = 1;
	while (line != NULL)
	{
		free (line);
		line = get_next_line(fd);
		if (map_length(line) != window.x && map_length(line) != 0)
			return (window.x = 0, window);
		columns++;
	}
	free(line);
	window.y = columns - 1;
	close(fd);
	return (window);
}

t_coord	init_coordinates(char *splitted, t_coord value, t_coord mapdim, int i)
{
	value.x = (float)(i % (int)mapdim.x) *2;
	value.y = (float)(i / (int)mapdim.x) *2;
	value.z = ft_atoi(splitted);
	value.h = value.z;
	value.z /= 2; //DIVIDIR POR LA DISTANCIA ENTRE MAX Y MIN
	return (value);
}

t_coord	*read_map(char *argv, t_coord mapdim)
{
	t_coord	*values;
	int		map_fd;
	char	*line;
	char	**splited;
	int		i;
	int		j;

	map_fd = open(argv, R_OK);
	if (map_fd < 0)
		return (NULL);
	line = get_next_line(map_fd);
	i = 0;
	values = malloc (sizeof(t_coord) * mapdim.x * mapdim.y);
	if (!values)
		return (NULL);
	while (line != NULL)
	{
		j = 0;
		splited = ft_split(line, ' ');
		while (splited[j] != NULL)
		{
			values[i] = init_coordinates(splited[j], values[i], mapdim, i);
			i++;
			j++;
		}
		ft_free(line, splited);
		line = get_next_line(map_fd);
	}
	free (line);
	close (map_fd);
	return (values);
}

int	main(int argc, char **argv)
{
	t_coord	map;
	t_vars	mlx;
	t_data	img;
	t_coord	*map_values;

	if (argc < 2)
		return (0);
	map = win_size(argv[1]);
	if (map.x == 0)
		return (write(2, "invalid map", 11));
	mlx.mlx = mlx_init();
	map_values = read_map(argv[1], map);
	mlx.win = mlx_new_window(mlx.mlx, WIN_W, WIN_H, "FDF");
	img.img = mlx_new_image(mlx.mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	grid(&img, map, map_values);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, register_hooks, &mlx);
	mlx_loop(mlx.mlx);
//NO ESTAS COMPILANDO CONFLAGs EN MAKEFILE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	return (0); 
}
