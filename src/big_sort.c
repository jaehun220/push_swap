/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:15:23 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/29 17:15:23 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack *a, t_stack *b)
{
	int		chunk_cnt;
	int		*bounds;
	t_node	*cur;

	if (!a || !b)
		return ;
	cur = a->top;
	chunk_cnt = chunk_count(a->size);
	bounds = make_chunk_bounds(a, chunk_cnt);
}
