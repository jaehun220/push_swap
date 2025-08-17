/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:47:36 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/23 16:47:36 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	get_min(t_stack *a)
{
	int		min;
	t_node	*tmp;

	tmp = a->top;
	min = tmp->value;
	while (tmp && tmp->next)
	{
		if (min > tmp->next->value)
			min = tmp->next->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_stack *a)
{
	int		max;
	t_node	*tmp;

	tmp = a->top;
	max = tmp->value;
	while (tmp && tmp->next)
	{
		if (max < tmp->next->value)
			max = tmp->next->value;
		tmp = tmp->next;
	}
	return (max);
}

int	is_sort(t_stack *a)
{
	t_node	*cur;

	if (!a || a->size <= 1)
		return (1);
	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->value <= cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->size != 0)
	{
		tmp = stack->top;
		stack->top = stack->top->prev;
		free(tmp);
		stack->size--;
	}
	free(stack);
}
