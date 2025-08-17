/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:42:45 by jaehlee           #+#    #+#             */
/*   Updated: 2025/04/04 15:42:45 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\r' || c == '\f' || c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}

int	print_error(int type)
{
	if (type >= 1)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_atoill(const char *str)
{
	long long	i;
	int			neg;

	i = 0;
	neg = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		i = i * 10 + (*str - '0');
		if ((neg == 1 && i > 2147483647)
			|| (neg == -1 && i * neg < -2147483648))
			print_error(1);
		str++;
	}
	return ((int)(i * neg));
}
