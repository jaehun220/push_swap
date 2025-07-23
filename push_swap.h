/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:52:43 by jaehlee           #+#    #+#             */
/*   Updated: 2025/07/22 16:52:43 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int		value;
	s_node *next;
	s_node *prev;
}t_node;

typedef struct s_stack
{
	int 	size;
	t_node *top;
	t_node *bottom;
}t_stack;

# endif