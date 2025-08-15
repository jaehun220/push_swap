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
	int		i;
	int		*distance;

	if (!a || !b)
		return ;
	chunk_cnt = chunk_count(a->size);
	bounds = make_chunk_bounds(a, chunk_cnt);
	i = 0;
	while (a->size > 1)
	{
		distance = get_distance(a, bounds, chunk_cnt);
		if (distance > 0)
		{
			while (distance--)
				ra(a);
		}
		else
		{
			while (distance++)
				rra(a);
		}
	}
}
