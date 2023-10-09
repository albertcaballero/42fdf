/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:30:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/09 17:41:30 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dim	win_size(int fd)
{
	t_dim	window;
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line[i] != 0 && line[i] != 10)
	{
		if (line[i] != 32 && line[i + 1] == 32)
			j++;
		i++;
	}
	window.x = j + 1;
	i = 1;
	while (get_next_line(fd) != NULL)
		i++;
	window.y = i;
	close(fd);
	return (window);
}

int	*read_map(char *argv, t_dim mapdim)
{
	int		*values;
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
	values = malloc (sizeof(int) * mapdim.x * mapdim.y);
	while (line != NULL)
	{
		j = 0;
		splited = ft_split(line, ' ');
		while (splited[j] != NULL)
			values[i++] = ft_atoi(splited[j++]);
		ft_free(line, splited);
		line = get_next_line(map_fd);
	}
	free (line);
	close (map_fd);
	return (values);
}

int	main(int argc, char **argv)
{
	int		map_fd;
	t_dim	window;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		*map_values;

	if (argc < 2)
		return (0);
	map_fd = open(argv[1], R_OK);
	if (map_fd < 0)
		return (0);
	mlx = mlx_init();
	window = win_size(map_fd);
	map_values = read_map(argv[1], window);
	mlx_win = mlx_new_window(mlx, 700, 700, "FDF");
	img.img = mlx_new_image(mlx, 700, 700);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	grid(&img, window, map_values);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	close (map_fd);
	return (0);
}