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
		return (13);
	return (18);
}

static int	find_up_dist(t_stack *a, int *bounds, int chunk_cnt, int target)
{
	int		up;
	t_node	*tmp;

	up = 0;
	tmp = a->top;
	while (tmp && chunk_bound_check(tmp->value, bounds, chunk_cnt) != target)
	{
		tmp = tmp -> next;
		up++;
	}
	if (tmp == NULL)
		return (-1);
	return (up);
}

static int	find_down_dist(t_stack *a, int *bounds, int chunk_cnt, int target)
{
	int		down;
	t_node	*tmp;

	down = 1;
	tmp = a->top;
	while (tmp && chunk_bound_check(tmp->value, bounds, chunk_cnt) != target)
	{
		tmp = tmp -> next;
		down++;
	}
	if (tmp == NULL)
		return (-1);
	return (down);
}

int	get_distance_a(t_stack *a, int *bounds, int chunk_cnt, int target)
{
	int		up;
	int		down;

	up = find_up_dist(a, bounds, chunk_cnt, target);
	down = find_down_dist(a, bounds, chunk_cnt, target);
	if (up == -1 && down == -1)
		return (0);
	if (up == -1)
		return (-down);
	if (down == -1)
		return (up);
	if (up <= down)
		return (up);
	return (-down);
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
