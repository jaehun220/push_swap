/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:49 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/12 14:19:49 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_arr(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*cur;

	if (!a || a->size <= 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	i = 0;
	cur = a->top;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->prev;
	}
	return (arr);
}

static void	arr_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	if (!arr || n <= 1)
		return ;
	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	check_idx(long idx, int size)
{
	if (idx < 0)
		return (0);
	if (idx >= size)
		return (size - 1);
	return ((int)idx);
}

int	*make_chunk_bounds(t_stack *a, int chunk_cnt)
{
	int		*src;
	int		*bounds;
	int		i;
	long	end_idx;

	if (!a || a->size <= 0 || chunk_cnt <= 0)
		return (NULL);
	if (chunk_cnt > a->size)
		chunk_cnt = a->size;
	src = stack_to_arr(a);
	if (!src)
		return (NULL);
	arr_sort(src, a->size);
	bounds = (int *)malloc(sizeof(int) * chunk_cnt);
	if (!bounds)
		return (free(src), NULL);
	i = 0;
	while (i < chunk_cnt)
	{
		end_idx = ((a->size) * (long)(i + 1)) / chunk_cnt - 1;
		bounds[i++] = src[check_idx(end_idx, a->size)];
	}
	return (free(src), bounds);
}

int	chunk_bound_check(int v, int *bounds, int chunk_cnt)
{
	int	i;

	if (!bounds || chunk_cnt <= 0)
		return (0);
	i = 0;
	while (i < chunk_cnt)
	{
		if (v <= bounds[i])
			return (i);
		i++;
	}
	return (chunk_cnt - 1);
}
