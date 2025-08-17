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

#include "push_swap.h"

static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static int	is_numeric_token(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	validate_tokens(char **sp)
{
	int	i;

	if (!sp || !sp[0])
		return (0);
	i = 0;
	while (sp[i])
	{
		if (!is_numeric_token(sp[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	*convert_tokens(char **sp, int count)
{
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	i = 0;
	while (sp[i])
	{
		arr[i] = (int)ft_atoill(sp[i]);
		i++;
	}
	return (arr);
}

int	*check_digit(char *str, int *count)
{
	char	**sp;
	int		*arr;
	int		c;

	if (!str || !count)
		return (NULL);
	sp = ft_split(str, ' ');
	if (!sp)
		return (NULL);
	if (!validate_tokens(sp))
		return (free_split(sp), NULL);
	c = 0;
	while (sp[c])
		c++;
	*count = c;
	arr = convert_tokens(sp, c);
	free_split(sp);
	return (arr);
}
