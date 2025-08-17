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
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}t_stack;

/* utils */
int		is_sort(t_stack *a);
int		get_min(t_stack *a);
int		get_max(t_stack *a);
void	free_stack(t_stack *stack);
int		get_distance_a(t_stack *a, int *bounds, int chunk_cnt);
int		get_distance_b(t_stack *b);

/*simple sort*/
int		get_index(t_stack *a, int v);
void	simple_sort(t_stack *a, t_stack *b);

/*big sort*/
void	big_sort(t_stack *a, t_stack *b);

/*make_chunk*/
int		chunk_count(int n);
int		*make_chunk_bounds(t_stack *a, int chunk_cnt);
int		chunk_bound_check(int v, int *bounds, int chunk_cnt);

/*check_arg*/
int		print_error(int type);
int		check_digit(const char *str, int *arr, int *count);
int		*parsing_arg(const char **argv);
int		has_duplicate(int *arr, int n);
int		validate_tokens(char **sp);
void	free_split(char **arr);
int		get_count(const char **argv);

/*스택 함수들*/
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

int		ft_atoill(const char *str);

/*stack*/
t_stack	*stack_init(void);
t_stack	*stack_fill(t_stack *a, int *arr, int count);

#endif