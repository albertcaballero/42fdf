/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:30:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/09 13:36:16 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	win_size(int fd)
{
	t_info	window;
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
	window.width = j + 1;
	i = 1;
	while (get_next_line(fd) != NULL)
		i++;
	window.height = i;
	close(fd);
	return (window);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	square(t_data *img, int w, int h, int xst, int yst)
{
	int	ix;
	int	iy;

	iy = yst;
	while (iy < h+yst)
	{
		ix = xst;
		while (ix < w + xst)
		{
			if (ix == xst || ix == w + xst - 1 || iy == yst || iy == h + yst - 1)
				my_mlx_pixel_put(img, ix, iy, 0x00FF0000);
			ix++;
		}
		iy++;
	}

}

void	grid(t_data *img, int w, int h)
{
	int	vert;
	int	horiz;
	int	xsize = 20;
	int	ysize = 20;

	vert = 0;
	while (vert < h)
	{
		horiz = 0;
		while (horiz < w)
		{
			square(img, xsize, ysize, 100 + xsize * horiz, 100 + ysize * vert);
			horiz++;
		}
		vert++;
	}
}

void	circle(t_data *img, int h)
{
	int	ix;
	int	iy;
	int	ii;

	iy = 0;
	ii = 0;
	while (iy < 400)
	{
		ix = 0;
		while (ix < 400)
		{
			if (pow((ix - 200), 2) + pow((iy - 200), 2) == pow(h / 2, 2))
			{
				my_mlx_pixel_put(img, ix, iy, 0x0000FF00);
				ft_printf("%i, %i ||", ix, iy);
				ii++;
			}
			ix++;
		}
		iy++;
	}
	ft_printf("%i", ii);

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

int	*read_map(char *argv, t_info mapdim)
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
	values = malloc (sizeof(int) * mapdim.width * mapdim.height);
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
	t_info	window;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		*map;

	if (argc < 2)
		return (0);
	map_fd = open(argv[1], R_OK);
	if (map_fd < 0)
		return (0);
	mlx = mlx_init();
	window = win_size(map_fd);
	map = read_map(argv[1], window);
	mlx_win = mlx_new_window(mlx, 700, 700, "FDF");
	img.img = mlx_new_image(mlx, 700, 700);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	grid(&img, window.width, window.height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	close (map_fd);
	return (0);
}