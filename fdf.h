/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:31:08 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/10 16:32:45 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_H 800
# define WIN_W 800

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_dimensions
{
	float	y;
	float	x;
	float	z;
}	t_dim;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	grid(t_data *img, t_dim win, int *values);
void	ft_free(char *gnline, char **splited);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		max_value(int *values, t_dim mapsize);
int		colors(int values, int maxval);
t_dim	get_point_coord(int *values, int i, t_dim win);

#endif