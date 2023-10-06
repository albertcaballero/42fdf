/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:30:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/06 18:20:25 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	win_size(int fd)
{
	t_info	window;
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line[i] != 0 && line[i] != 10)
		i++;
	window.width = i;
	i = 1;
	while (get_next_line(fd) != NULL)
		i++;
	window.height = i;
	return (window);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	square(t_data *img, int x, int y)
{
	int	ix;
	int	iy;

	iy = 10;
	while (iy < y)
	{
		ix = 10;
		while (ix < x)
		{
			my_mlx_pixel_put(img, ix, iy, 0x00FF0000);
			ix++;
		}
		iy++;
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
			if (pow((ix-200), 2)+pow((iy-200), 2) == pow(h/2, 2))
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

int	main(int argc, char **argv)
{
	int		map_fd;
	t_info	window;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (argc < 2)
		return (0);
	map_fd = open(argv[1], R_OK);
	if (map_fd < 0)
		return (0);
	mlx = mlx_init();
	window = win_size(map_fd);
	mlx_win = mlx_new_window(mlx, 400, 400, "FDF");
	img.img = mlx_new_image(mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//square(&img, 200, 200);
	circle(&img, 200);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}