/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:18:47 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/08 23:36:12 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_atoib_digit(char c)
{
	if (c >= '0' && c <= '9' && c <= 'f')
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= 'f')
		return (10 + c - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str)
{
	int	i;
	int	numb;

	i = 0;
	numb = 0;
	if (str == NULL)
		return (0);
	i += 3;
	while ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 'a' && str[i] <= 'f'))
	{
		numb = (numb * 16 + (str[i] - get_atoib_digit(str[i])));
		i++;
	}
	return (numb);
}

void	print_movements(void)
{
	ft_printf("Move: W, A, S, D\n");
	ft_printf("Zoom: +, -\n");
	ft_printf("Rotate X: UP, DOWN\n");
	ft_printf("Rotate Y: 7, 8\n");
	ft_printf("Rotate Z: LEFT, RIGHT\n");
	ft_printf("Scale: *, /\n");
	ft_printf("Color: SPACE\n");
}
