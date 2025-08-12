/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_chunk2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:59:10 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/12 15:59:10 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	chunk_count(int n)
{
	if (n <= 0)
		return (1);
	else if (n <= 100)
		return (6);
	else if (n <= 500)
		return (11);
	return (18);
}

int	get_instance(t_stack *a)
{
	
}
