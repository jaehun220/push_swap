/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:57:53 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/23 15:57:53 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static void	push(t_stack *dest, t_stack *src)
{
	t_node	*tmp;

	if (src->size == 0)
		return ;
	tmp = src->top;
	src->top = src->top->prev;
	if (src->top)
		src->top->next = NULL;
	src->size--;
	tmp->prev = dest->top;
	if (dest->top)
		dest->top->next = tmp;
	tmp->next = NULL;
	dest->top = tmp;
	dest->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
