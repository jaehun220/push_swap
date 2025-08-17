/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:57:33 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/17 20:57:33 by jaehlee          ###   ########.fr       */
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
	stack->bottom = tmp->prev;
	stack->bottom->next = NULL;
	tmp->next = stack->top;
	tmp->prev = NULL;
	stack->top->prev = tmp;
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
