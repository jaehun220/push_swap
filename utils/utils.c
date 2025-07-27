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
#include "push_swap.h"

int	get_min(t_stack *a)
{
	int		min;
	t_node	*tmp;

	tmp = a->top;
	min = tmp->value;
	while (tmp && tmp->prev)
	{
		if (min > tmp->prev->value)
			min = tmp->prev->value;
		tmp = tmp->prev;
	}
	return (min);
}

int	get_max(t_stack *a)
{
	int		max;
	t_node	*tmp;

	tmp = a->top;
	max = tmp->value;
	while (tmp && tmp->prev)
	{
		if (max < tmp->prev->value)
			max = tmp->prev->value;
		tmp = tmp->prev;
	}
	return (max);
}

int	is_sort(t_stack *a)
{
	t_node	*head;

	if (a->size == 0 || a->size == 1)
		return (1);
	head = a->top;
	while (head && head->prev)
	{
		if (head->value > head->prev->value)
			return (0);
		head = head->prev;
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
