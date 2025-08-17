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
/*split한거 free*/
void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/*문자열에 숫자만 있는지 체크*/
static int	is_numeric_token(const char *s)
{
	int	i;

	i = 0;
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

/*문자열 배열에 숫자만 있는지 체크*/
int	validate_tokens(char **sp)
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

/*int arr배열에 문자열 배열에 있는 숫자 인자들을 int형으로 바꿔서 밀*/
int	check_digit(const char *str, int *arr, int *count)
{
	char	**sp;
	int		i;

	if (!str ||! arr || !count)
		return (-1);
	sp = ft_split(str, ' ');
	if (!sp)
		return (-1);
	if (!validate_tokens(sp))
		return (free_split(sp), -1);
	i = 0;
	while (sp[i])
	{
		arr[*count++] = ft_atoill(sp[i]);
		i++;
	}
	free_split(sp);
	return (0);
}
