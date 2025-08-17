/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:57:46 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/23 15:57:46 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
/*마지막꺼 처음으로*/
static void	reverse(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->bottom;
	stack->bottom = tmp->next;
	stack->bottom->prev = NULL;
	tmp->next = NULL;
	tmp->prev = stack->top;
	stack->top->next = tmp;
	stack->top = tmp;
}

void	rra(t_stack *a)
{
	reverse(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	reverse(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	ft_putstr_fd("rrr\n", 1);
}
