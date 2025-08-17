/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:34:09 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/25 18:34:09 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	get_index(t_stack *a, int v)
{
	int		index;
	t_node	*tmp;

	index = 1;
	tmp = a->top;
	while (tmp && tmp->next)
	{
		if (tmp->value == v)
			return (index);
		index++;
	}
	return (-1);
}

static void	sort3(t_stack *a)
{
	int	max_idx;
	int	min_idx;

	max_idx = get_index(a, get_max(a));
	min_idx = get_index(a, get_min(a));
	if (min_idx == 1)
	{
		sa(a);
		ra(a);
	}
	else if (min_idx == 2)
	{
		if (max_idx == 3)
			sa(a);
		else if (max_idx == 1)
			ra(a);
	}
	else if (min_idx == 3)
	{
		if (max_idx == 1)
			sa(a);
		rra(a);
	}
}

static void	sort4(t_stack *a, t_stack *b)
{
	int	min_idx;

	if (is_sort(a))
		return ;
	min_idx = get_index(a, get_min(a));
	if (min_idx == 2)
		ra(a);
	else if (min_idx == 3 || min_idx == 4)
	{
		if (min_idx == 3)
			rra(a);
		rra(a);
	}
	if (is_sort(a))
		return ;
	pb(a, b);
	sort3(a);
	pa(a, b);
}

static void	sort5(t_stack *a, t_stack *b)
{
	int	min_idx;

	if (is_sort(a))
		return ;
	min_idx = get_index(a, get_min(a));
	if (min_idx == 2 || min_idx == 3)
	{
		if (min_idx == 3)
			ra(a);
		ra(a);
	}
	if (min_idx == 4 || min_idx == 5)
	{
		if (min_idx == 4)
			rra(a);
		rra(a);
	}
	if (is_sort(a))
		return ;
	pb(a, b);
	sort4(a, b);
	pa(a, b);
}

void	simple_sort(t_stack *a, t_stack *b)
{
	if (is_sort(a))
		return ;
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort3(a);
	else if (a->size == 4)
		sort4(a, b);
	else if (a->size == 5)
		sort5(a, b);
}
