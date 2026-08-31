/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/19 13:24:11 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 11:31:06 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE,
	STRAT_INVALID
}	t_strategy;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

typedef struct s_node
{
	int				content;
	int				rank;
	struct s_node	*next;
}	t_node;

typedef struct s_bench
{
	int	counts[OP_COUNT];
	int	total_ops;
	int	enabled;
}	t_bench;

/* Bench operations */
void	track_op(t_bench *bench, t_op op);
void	print_bench(t_strategy strategy, double disorder, t_bench *bench);

/* Swap operations */
void	op_sa(t_node **stack_a, t_bench *bench);
void	op_sb(t_node **stack_b, t_bench *bench);
void	op_ss(t_node **stack_a, t_node **stack_b, t_bench *bench);

/* Push operations */
void	op_pa(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	op_pb(t_node **stack_a, t_node **stack_b, t_bench *bench);

/* Rotate operations */
void	rotate_silent(t_node **head);
void	reverse_rotate_silent(t_node **head);
void	op_ra(t_node **stack_a, t_bench *bench);
void	op_rb(t_node **stack_b, t_bench *bench);
void	op_rra(t_node **stack_a, t_bench *bench);
void	op_rrb(t_node **stack_b, t_bench *bench);
void	op_rr(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	op_rrr(t_node **stack_a, t_node **stack_b, t_bench *bench);

/* Utility functions */
t_strategy	check_forced(char *forced_command);
void		run_algo(t_strategy strategy, t_node **stack_a, t_node **stack_b, t_bench *bench);
int			parse_options(char **av, int ac, t_strategy *strategy, int *bench);
void		rank_numbers(t_node **initial_stack);

/* Stack functions */
t_node	*initialize_stack(char **av, int ac);

/* Linked list functions */
void	insert_at_tail(t_node **lst, t_node *new);
void	insert_at_head(t_node **lst, t_node *new);
t_node	*new_node(int content);
t_node	*find_last_node(t_node *lst);
void	free_stack(t_node **stack);

/* Sorting functions */
void	simple_sort(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	medium_sort(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	complex_sort(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	adaptive_sort(t_node **stack_a, t_node **stack_b, t_bench *bench);

/* Sorting utils functions */
int	try_sort_small(t_node **stack_a, t_bench *bench);
int	stack_size(t_node *stack);
int	is_sorted(t_node *stack);

/* Disorder functions */
double	compute_disorder(int element_count, t_node *stack_a);

#endif
