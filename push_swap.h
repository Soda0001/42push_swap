/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:24:11 by alterzi           #+#    #+#             */
/*   Updated: 2026/08/30 15:32:56 by sedeniz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE,
	STRAT_INVALID
}	t_strategy;

typedef struct s_node
{
	int				content;
	int				rank;
	struct s_node	*next;
}	t_node;

/* Swap operations */
void	op_sa(t_node **head);
void	op_sb(t_node **head);
void	op_ss(t_node **head_a, t_node **head_b);

/* Push operations */
void	op_pa(t_node **head_a, t_node **head_b);
void	op_pb(t_node **head_a, t_node **head_b);

/* Rotate operations */
void	rotate_silent(t_node **head);
void	reverse_rotate_silent(t_node **head);
void	op_ra(t_node **head_a);
void	op_rb(t_node **head_b);
void	op_rra(t_node **head_a);
void	op_rrb(t_node **head_b);
void	op_rr(t_node **head_a, t_node **head_b);
void	op_rrr(t_node **head_a, t_node **head_b);

/* Utility functions */
t_strategy	check_forced(char *forced_command);
void		run_algo(t_strategy strategy, t_node **stack_a, t_node **stack_b);
int			parse_options(char **av, int ac, t_strategy *strategy, int *bench);
void		rank_numbers(t_node **initial_stack);

/* Stack functions */
t_node	*initialize_stack(char **av, int ac, int start);

/* Linked list functions */
void	insert_at_tail(t_node **lst, t_node *new);
void	insert_at_head(t_node **lst, t_node *new);
t_node	*new_node(int content);
t_node	*find_last_node(t_node *lst);
void	free_stack(t_node **stack);

/* Sorting functions */
void	simple_sort(t_node **stack_a, t_node **stack_b);
void	medium_sort(t_node **stack_a, t_node **stack_b);
void	complex_sort(t_node **stack_a, t_node **stack_b);
void	adaptive_sort(t_node **stack_a, t_node **stack_b);

/* Sorting utils functions */
int	try_sort_small(t_node **stack_a);
int	stack_size(t_node *stack);

/* Disorder functions */
double	compute_disorder(int element_count, t_node *stack_a);

#endif
