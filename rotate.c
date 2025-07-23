/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:57:49 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/23 15:57:49 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*처음꺼 마지막으로*/
static void	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->top;
	stack->top = tmp->prev;
	stack->top->next = NULL;
	tmp->prev = NULL;
	tmp->next = stack->bottom;
	stack->bottom->prev = tmp;
	stack->bottom = tmp;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr("ra");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr("rb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr");
}
