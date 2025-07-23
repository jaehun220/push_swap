/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:57:51 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/23 15:57:51 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size == 0 || stack->size == 1)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->prev->value;
	stack->top->prev->value = temp;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putstr("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
