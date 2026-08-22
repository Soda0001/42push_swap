/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:24:11 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/22 14:55:03 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE,
	STRAT_INVALID
}	t_strategy;

/*
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_list;
*/

/* Swap operations*/
void	op_sa(t_list **head);
void	op_sb(t_list **head);
void	op_ss(t_list **head_a, t_list **head_b);

/* Push operations */
void	op_pa(t_list **head_a, t_list **head_b);
void	op_pb(t_list **head_a, t_list **head_b);

/* Rotate operations */
void	op_ra(t_list **head_a);
void	op_rb(t_list **head_b);
void	op_rra(t_list **head_a);
void	op_rrb(t_list **head_b);
void	op_rr(t_list **head_a, t_list **head_b);
void	op_rrr(t_list **head_a, t_list **head_b);

/* Utility functions */
int	determine_start(char *first_arg);

#endif