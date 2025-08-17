/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:06:47 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/27 21:06:47 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*str에 숫자가 몇개 있는지 체크*/
static int	count_tokens(const char *str)
{
	char	**sp;
	int		c;

	sp = ft_split(str, ' ');
	if (!sp)
		return (-1);
	if (!validate_tokens(sp))
		return (free_split(sp), -1);
	c = 0;
	while (sp[c])
		c++;
	free_split(sp);
	return (c);
}

int	get_count(const char **argv)
{
	int	i;
	int	count;
	int	total;

	i = 1;
	total = 0;
	count = 0;
	while (argv[i])
	{
		count = count_tokens(argv[i]);
		if (count < 0)
			return (-1);
		total += count;
		i++;
	}
	return (total);
}

int	has_duplicate(int *arr, int n)
{
	int	i;
	int	j;

	if (!arr || n <= 1)
		return (0);
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parsing_arg(const char **argv)
{
	int	total;
	int	i;
	int	count;
	int	*arr;

	total = get_count(argv);
	if (total < 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * total);
	if (!arr)
		return (NULL);
	count = 0;
	i = 1;
	while (argv[i])
	{
		if (check_digit(argv[i], arr, &count, total) != 0)
			return (free(arr), NULL);
		i++;
	}
	return (arr);
}
