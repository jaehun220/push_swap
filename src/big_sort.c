/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:15:23 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/29 17:15:23 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	a_to_b(t_stack *a, t_stack *b, int *bounds, int chunk_cnt)
{
	int	distance;

	while (a->size > 5)
	{
		distance = get_distance_a(a, bounds, chunk_cnt);
		if (distance > 0)
		{
			while (distance--)
				ra(a);
		}
		else
		{
			while (distance++)
				rra(a);
		}
		pb(a, b);
	}
}

static void	b_to_a(t_stack *a, t_stack *b)
{
	int	distance;

	while (b->size > 0)
	{
		distance = get_distance_b(b);
		if (distance > 0)
		{
			while (distance--)
				rb(b);
		}
		else
		{
			while (distance++)
				rrb(b);
		}
		pa(a, b);
	}
}

void	big_sort(t_stack *a, t_stack *b)
{
	int		chunk_cnt;
	int		*bounds;

	if (!a || !b)
		return ;
	chunk_cnt = chunk_count(a->size);
	bounds = make_chunk_bounds(a, chunk_cnt);
	if (!bounds)
		return ;
	a_to_b(a, b, bounds, chunk_cnt);
	simple_sort(a, b);
	b_to_a(a, b);
	free(bounds);
}
