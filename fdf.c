/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:30:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/06 12:56:06 by alcaball         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		map_fd;
	t_info	window;
	void	*mlx;

	if (argc < 2)
		return (0);
	map_fd = open(argv[1], R_OK);
	if (map_fd < 0)
		return (0);
	mlx = mlx_init();
	window = win_size(map_fd);
	ft_printf("%i %i", window.height, window.width);
	return (0);
}