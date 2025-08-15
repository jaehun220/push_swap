/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:06:47 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/27 21:06:47 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int type)
{
	if (type >= 1)
		ft_putstr("Error\n", 2);
	exit(1);
}

int	error_check(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**arg_list;

	i = 1;
	while (argv[i])
	{
		j = 0;
		arg_list = ft_split(argv[i], ' ');
		if (arg_list == NULL)
			return (-1);
		if (ft_isdigit(arg_list[j]) == 0)
			return (free(arg_list), -1);
		
	}
}
