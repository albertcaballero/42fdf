/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:30:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/12 13:12:20 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	win_size(char *argv)
{
	t_coord	window;
	int		fd;
	int		columns;
	char	*line;

	fd = open(argv[1], R_OK);
	if (fd < 0)
		return (window.x = 0, window);
	line = get_next_line(fd);
	window.x = map_length(line);
	columns = 1;
	while (line != NULL)
	{
		free (line);
		line = get_next_line(fd);
		if (map_length(line) != window.x)
			return (window.x = 0, window);
		columns++;
	}
	free(line);
	window.y = columns;
	close(fd);
	return (window);
}

t_coord	init_coordinates(char *splitted, t_coord value, t_coord mapdim, int i)
{
	value.x = (i / mapdim.x) * 2;
	value.y = (i % mapdim.x) * 2;
	value.z = ft_atoi(splitted);

	// value.x = value.x + value.z * (sqrt(3) / 2);
	// value.y = value.y - value.z * 0.5;
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
	while (line != NULL)
	{
		j = 0;
		splited = ft_split(line, ' ');
		while (splited[j++] != NULL)
			values[i++] = init_coordinates(splited[j], values[i], mapdim, i);
		ft_free(line, splited);
		line = get_next_line(map_fd);
	}
	free (line);
	close (map_fd);
	return (values);
}

int	main(int argc, char **argv)
{
	t_coord	window;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_coord	*map_values;

	if (argc < 2)
		return (0);
	window = win_size(argv[1]);
	if (window.x == 0)
		return (write(2, "invalid map", 11));
	mlx = mlx_init();
	map_values = read_map(argv[1], window);
	mlx_win = mlx_new_window(mlx, WIN_W, WIN_H, "FDF");
	img.img = mlx_new_image(mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	grid(&img, window, map_values);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
