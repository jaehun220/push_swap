/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:38:23 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/23 15:38:23 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	main(int argc, char const *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;

	if (argc < 2)
		print_error(0);
	arr = parsing_arg(argc, argv);
	if (!arr)
		print_error(1);
	if (has_duplicate(arr, count_tokens(arr)))
		print_error(1);
	a = stack_init();
	b = stack_init();
	a = stack_fill(a, arr, count_tokens(arr));
	if (argc <= 5)
		simple_sort(a, b);
	else
		big_sort(a, b);
	return (0);
}
