/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:57:47 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/17 20:57:47 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack *dest, t_stack *src)
{
	t_node	*tmp;

	if (src->size == 0)
		return ;
	tmp = src->top;
	src->top = tmp->next;
	if (src->size > 1)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	tmp->next = dest->top;
	if (dest->size > 0)
		dest->top->prev = tmp;
	tmp->prev = NULL;
	dest->top = tmp;
	if (dest->size == 0)
		dest->bottom = tmp;
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
