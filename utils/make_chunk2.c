/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_chunk2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:34:32 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/15 15:34:32 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static t_node	*find_up_idx(t_stack *a, int *bounds, int chunk_cnt, int *up)
{
	t_node	*tmp;

	*up = 0;
	tmp = a->top;
	while (tmp && !chunk_bound_check(tmp->value, bounds, chunk_cnt))
	{
		tmp = tmp->next;
		*up += 1;
	}
	return (tmp);
}

static t_node	*find_down_idx(t_stack *a, int *bounds, int cnt, int *down)
{
	t_node	*tmp;

	*down = 1;
	tmp = a->bottom;
	while (tmp && !chunk_bound_check(tmp->value, bounds, cnt))
	{
		tmp = tmp->prev;
		*down += 1;
	}
	return (tmp);
}

int	get_distance_a(t_stack *a, int *bounds, int chunk_cnt)
{
	t_node	*up_node;
	t_node	*down_node;
	int		up;
	int		down;

	up_node = find_up_idx(a, bounds, chunk_cnt, &up);
	down_node = find_down_idx(a, bounds, chunk_cnt, &down);
	if (up > down)
		return (-down);
	else if (up < down)
		return (up);
	else
	{
		if (up_node->value < down_node->value)
			return (up);
		else
			return (-down);
	}
}

int	get_distance_b(t_stack *b)
{
	int		max;
	int		distance;
	t_node	*temp;

	max = get_max(b);
	distance = 0;
	temp = b->top;
	while (temp->value != max)
	{
		temp = temp->next;
		distance++;
	}
	if (distance <= (b->size - distance))
		return (distance);
	return (distance - b->size);
}
