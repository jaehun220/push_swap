/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:54:21 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/17 14:54:21 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_node	*node_init(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_stack	*stack_fill(t_stack *a, int *arr, int count)
{
	int		i;
	t_node	*new;

	i = 0;
	while (i < count)
	{
		new = node_init(arr[i]);
		if (!new)
			return (NULL);
		if (a->size == 0)
		{	
			a->bottom = new;
			a->top = new;
		}
		else
		{
			new->next = a->top;
			a->top->prev = new;
			a->top = new;
		}
		a->size++;
		i++;
	}
	return (a);
}
