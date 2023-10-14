/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:31:08 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/14 21:52:20 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_H 800
# define WIN_W 800

# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define CYAN 0x00FFFF
# define YELLOW 0xFFFF00
# define BLACK 0x000000
# define TURQ 0x5DC1B9
# define SPRING 0x5ef38c
# define FAN 0xa80874

# define ESC 53
# define K 40
# define L 37
# define I 34
# define M 46
# define U 32
# define O 31
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define V 9
# define B 11

# define ADD 1
# define DIVIDE 2
# define MAX 1
# define MIN 0

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

typedef struct s_coordinates
{
	float	y;
	float	x;
	float	z;
	float	h;
}	t_coord;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
	int	all;
}	t_colors;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_input
{
	int	zoom;
	int	mvx;
	int	mvy;
	int	rotx;
	int	roty;
	int	rotz;
	int	height;
}	t_input;

size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	grid(t_data *img, t_coord win, t_coord *values, t_input input);
void	ft_free(char *gnline, char **splited);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		max_value(t_coord *values, t_coord map, int flag);
int		colors(t_coord point, t_coord next, int i, int max);
t_coord	start_draw_coord(t_coord point, t_input input);
int		map_length(char	*line);
t_coord	scale(t_coord coord, t_input input);
t_coord	translation(t_coord coord, t_input input);
t_coord	rotation(t_coord coord, t_input input);
void	clear_screen(t_data *img);
int		register_hooks (int key, t_input input);
t_input	init_input(t_input inp);

#endif