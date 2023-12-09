/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:18:47 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/09 13:42:55 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_base(const char *str)
{
	int	i;
	int	result;

	i = 3;
	result = 0;
	if (str == NULL)
		return (0);
	while (str[i] != 0)
	{
		result *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result += str[i] - '7';
		else if (str[i] >= 'a' && str[i] <= 'z')
			result += str[i] - 'W';
		i++;
	}
	return (result);
}

void	print_movements(void)
{
	ft_printf("Move: W, A, S, D\n");
	ft_printf("Zoom: Z, X\n");
	ft_printf("Rotate X: UP, DOWN\n");
	ft_printf("Rotate Y: ., ,\n");
	ft_printf("Rotate Z: LEFT, RIGHT\n");
	ft_printf("Scale: *, /\n");
	ft_printf("Lines: SPACE\n");
}
