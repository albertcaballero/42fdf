/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:31:08 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/06 12:54:41 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);

typedef struct s_information
{
	int	height;
	int	width;
}	t_info;


#endif