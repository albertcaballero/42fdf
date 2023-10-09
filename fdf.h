/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:31:08 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/09 14:38:02 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_dimensions
{
	int	h;
	int	w;
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




#endif