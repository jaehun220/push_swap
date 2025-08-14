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

int	*get_instance(t_stack *a, int value)
{
	t_node	*next;
	t_node	*prev;
	int		up;
	int		down;
	int		distance[2];

	down = 0;
	up = 1;
	prev = a->top;
	next = a->bottom;
	while (next->value != value || prev->value != value)
	{
		next = next->next;
		prev = prev->prev;
		up++;
		down++;
	}
	distance[0] = up;
	distance[1] = down;
	return (distance);
}
