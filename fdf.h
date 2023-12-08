/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:31:08 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/08 01:21:17 by albert           ###   ########.fr       */
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
# define K_4 86
# define K_6 88
# define K_8 91
# define K_2 84
# define K_7 89
# define K_9 92
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define K_MEN 78
# define K_PLUS 69
# define DIV 75
# define MULT 67

# define CLOSE 17

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

typedef struct s_coordinates
{
	float	y;
	float	x;
	float	z;
	float	h;
}	t_coord;

typedef struct s_map
{
	float	x;
	float	y;
	long	count;
	char	*argv;
	int		fd;
	int		max;
	int		min;
}	t_map;

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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_data	img;
	t_input	keys;
	t_coord	*ini;
}	t_mlx;

size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	grid(t_mlx *mlx, t_map map);
void	ft_free(char *gnline, char **splited);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		max_value(t_coord *values, t_map map, int flag);
int		colors(t_coord point, t_coord next, int i, t_map map);
void	start_draw_coord(t_coord *point, t_coord ini, t_input input);
int		map_length(char	*line);
void	scale(t_coord *coord, t_input input);
void	translation(t_coord *coord, t_input input);
void	rotation(t_coord *coord, t_input input);
void	clear_screen(t_data *img);
int		register_hooks(int key, t_mlx *mlx);
t_input	init_input(t_input inp);
int		close_program(t_mlx *mlx);
t_coord	*read_map(t_map *map, int i);

#endif