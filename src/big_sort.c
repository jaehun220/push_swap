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

static int	has_chunk_in_a(t_stack *a, int *bounds, int chunk_cnt, int target)
{
	t_node	*p;

	if (!a || a->size == 0)
		return (0);
	p = a->top;
	while (p)
	{
		if (chunk_bound_check(p->value, bounds, chunk_cnt) == target)
			return (1);
		p = p->next;
	}
	return (0);
}

static void	a_to_b(t_stack *a, t_stack *b, int *bounds, int chunk_cnt)
{
	int	i;
	int	d;

	i = 0;
	while (i < chunk_cnt && a->size > 0)
	{
		if (!has_chunk_in_a(a, bounds, chunk_cnt, i))
		{
			i++;
			continue ;
		}
		d = get_distance_a(a, bounds, chunk_cnt, i);
		if (d > 0)
			while (d--)
				ra(a);
		else if (d < 0)
			while (d++)
				rra(a);
		pb(a, b);
	}
	while (a->size > 0)
		pb(a, b);
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
			while (distance++ < 0)
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
