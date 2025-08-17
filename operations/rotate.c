/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:57:38 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/17 20:57:38 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*처음꺼 마지막으로*/
static void	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->top;
	stack->top = tmp->next;
	stack->top->prev = NULL;
	tmp->prev = stack->bottom;
	stack->bottom->next = tmp;
	stack->bottom = tmp;
	tmp->next = NULL;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
