/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:24:11 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/23 17:53:18 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

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
	struct s_node	*next;
}	t_node;


/* Swap operations*/
void	op_sa(t_node **head);
void	op_sb(t_node **head);
void	op_ss(t_node **head_a, t_node **head_b);

/* Push operations */
void	op_pa(t_node **head_a, t_node **head_b);
void	op_pb(t_node **head_a, t_node **head_b);

/* Rotate operations */
void	op_ra(t_node **head_a);
void	op_rb(t_node **head_b);
void	op_rra(t_node **head_a);
void	op_rrb(t_node **head_b);
void	op_rr(t_node **head_a, t_node **head_b);
void	op_rrr(t_node **head_a, t_node **head_b);

/* Utility functions */
//int			determine_start(char *first_arg);
t_strategy	check_forced(char *forced_command);
void		run_algo(t_strategy strategy, t_node **stack);
int			parse_options(char **av, int ac, t_strategy *strategy, int *bench);

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

#endif